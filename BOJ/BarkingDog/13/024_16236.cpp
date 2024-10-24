#include<iostream>
#include<queue>
#include<climits> //INT_MAX
using namespace std;

struct Shark {
	int y, x, time;
};
Shark shark;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, board[21][21], shark_size, shark_eat;
bool visited[21][21];

void go() {
	bool flag = true;

	while (flag) { //먹을 수 있는 물고기가 있다면 true
		flag = false; //조사를 시작할 때는 false로 가정

		fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);
		visited[shark.y][shark.x] = true; //시작점 방문처리

		board[shark.y][shark.x] = 0; //시작점의 좌표값 0으로 변경

		queue<Shark> q; //가장 적합한 물고기를 찾기 위한 bfs 시작
		q.push(shark);

		Shark candi; //candidate
		candi.time = -1; candi.y = INT_MAX;

		while (!q.empty()) {
			Shark cur = q.front(); q.pop();

			//입력된 cur의 시간이 최초로 갱신된 candi의 시간보다 길다면 break
			if (candi.time != -1 && candi.time < cur.time) break;

			//먹을 수 있는 물고기가 있다면
			if (board[cur.y][cur.x] != 0 && board[cur.y][cur.x] < shark_size) {
				flag = true;

				//먹을 수 있는 물고기들 중 가장 적합한 물고기를 candi에 저장
				if (cur.y < candi.y || (cur.y == candi.y && cur.x < candi.x)) {
					candi = cur;
				}
			}

			for (int i = 0; i < 4; i++) {
				Shark next;

				next.y = cur.y + dy[i];
				next.x = cur.x + dx[i];
				next.time = cur.time + 1;

				if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) continue;

				if (!visited[next.y][next.x] && board[next.y][next.x] <= shark_size) {
					visited[next.y][next.x] = true;
					q.push(next);
				}
			}
		}

		//먹을 수 있는 물고기가 있다면
		if (flag) {
			shark = candi; //아기 상어가 가장 적합한 물고기를 잡아먹고 정보를 변경한다
			shark_eat++;

			if (shark_eat == shark_size) {
				shark_size++;
				shark_eat = 0;
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];

			if (board[i][j] == 9) {
				shark = { i,j,0 };

				shark_size = 2;
				shark_eat = 0;
			}
		}
	}

	go();

	cout << shark.time;

	return 0;
}
