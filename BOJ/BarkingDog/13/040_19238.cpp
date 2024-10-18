#include<iostream>
#include<queue>
using namespace std;

struct Customer {
	int start; //출발 지점의 y좌표 * 100 + x좌표
	int end; //도착 지점의 y좌표 * 100 + x좌표
};
Customer customer[400]; //20 * 20이므로 최대 400명의 승객

struct Taxi {
	int pos; //택시가 이동하는 y좌표 * 100 + x좌표
	int distance; //한칸씩 이동하면서 증가하는 거리
};

const int WALL = -1;
const int EMPTY = -2;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int n, m, fuel, taxi_y, taxi_x, board[20][20];
int ret = -1;

int find_shortest_customer() {
	bool visited[20][20] = { false, };
	visited[taxi_y][taxi_x] = true;

	queue<Taxi> q;
	q.push({ taxi_y * 100 + taxi_x, 0 });

	int candi[400] = { 0, }; //택시의 현 좌표에서 가장 가까운 거리에 있는 승객의 번호만을 저장
	int candi_idx = 0;
	int candi_distance = -1;

	while (!q.empty()) { //bfs를 통해 최단거리의 승객을 찾아낸다
		Taxi cur = q.front(); q.pop();

		//갱신되었는데 기존의 거리보다 멀다면 break(feat. 16236 아기상어)
		if (candi_distance != -1 && candi_distance < cur.distance) break;

		//택시 좌표부터 탐색(택시인 동시에 승객이 있을 가능성. distance는 0이 되겠다)
		int y = cur.pos / 100;
		int x = cur.pos % 100;

		if (board[y][x] >= 0) { //승객이라면
			candi[candi_idx] = board[y][x]; //해당 승객의 번호를 candi 목록에 저장
			candi_idx++; //인덱스 증가(승객의 번호와 인덱스는 다른 개념이다)

			candi_distance = cur.distance;
		}

		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (board[ny][nx] == WALL || visited[ny][nx]) continue;

			visited[ny][nx] = true;
			q.push({ ny * 100 + nx, cur.distance + 1 });
		}
	}

	//가장 가까운 승객을 태울 연료가 부족하다면
	if (candi_distance > fuel) return -1;

	//우선순위(행번호 * 100 + 열번호)를 적용해 승객 선택
	int ret = -1; //승객 인덱스
	int candi_val = 10000; //pos(행번호 * 100 + 열번호)와 비교

	for (int i = 0; i < candi_idx; i++) {
		if (candi_val > customer[candi[i]].start) {
			candi_val = customer[candi[i]].start; //행번호, 열번호가 작은 승객 선택
			ret = candi[i]; //가장 작은 승객의 번호 저장
		}
	}

	//정해진 승객의 좌표로 택시의 좌표 변경
	taxi_y = customer[ret].start / 100;
	taxi_x = customer[ret].start % 100;

	//위치로 이동 후 승객을 태운다
	board[taxi_y][taxi_x] = EMPTY;

	//이동하는 과정에서 연료 소모
	fuel -= candi_distance;

	return ret; //승객의 번호 반환
}

bool move_customer(int selected_customer_idx) {
	bool visited[20][20] = { false, };
	visited[taxi_y][taxi_x] = true;

	queue<Taxi> q;
	q.push({ taxi_y * 100 + taxi_x, 0 }); //find_shortest_customer 함수로 정해진 택시의 좌표를 시작점으로 삼는다

	while (!q.empty()) {
		Taxi cur = q.front(); q.pop();

		//목적지까지 연료가 부족하다면
		if (cur.distance > fuel) return false;

		//목적지까지 도달했다면
		if (cur.pos == customer[selected_customer_idx].end) {
			taxi_y = customer[selected_customer_idx].end / 100;
			taxi_x = customer[selected_customer_idx].end % 100;

			fuel += cur.distance;

			//승객을 목적지로 이동시킨 동시에 연료가 바닥나는 경우는 실패한 것으로 간주하지 않는다
			return true;
		}

		int y = cur.pos / 100;
		int x = cur.pos % 100;

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (board[ny][nx] == WALL || visited[ny][nx] == true) continue;

			visited[ny][nx] = true;
			q.push({ ny * 100 + nx, cur.distance + 1 });
		}
	}

	return false;
}

void go() {
	for (int i = 0; i < m; ++i) { //승객 전체 검사
		int target = find_shortest_customer(); //가장 가까운 승객의 번호를 target으로 저장

		if (target == -1) {
			return;
		}

		bool success = move_customer(target); //해당 번호의 승객을 옮길 수 있는 지 여부

		if (success == false) {
			return;
		}
	}

	ret = fuel;

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> fuel;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];

			board[i][j] -= 2; //WALL = -1, EMPTY = -2, 승객 번호 >= 0
		}
	}

	cin >> taxi_y >> taxi_x;
	taxi_y--; taxi_x--; //인덱싱

	for (int i = 0; i < m; i++) { //0번째 승객부터 입력받는다
		int sy, sx, ey, ex;

		cin >> sy >> sx >> ey >> ex;
		sy--; sx--; ey--; ex--; //인덱싱

		//그중 행 번호가 가장 작은 승객을, 그런 승객도 여러 명이면 그중 열 번호가 가장 작은 승객을 고른다
		//둘 다 작은 경우이므로 아래와 같은 테크닉이 가능하다, 둘 다 큰 경우도 가능하다
		customer[i].start = (sy * 100 + sx);
		customer[i].end = (ey * 100 + ex);

		board[sy][sx] = i; //격자에 승객의 번호(인덱스)를 남긴다
	}

	go();

	cout << ret;

	return 0;
}
