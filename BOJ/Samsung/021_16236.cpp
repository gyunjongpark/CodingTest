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
int n, a[21][21], shark_size, shark_eat;
bool visited[21][21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];

			if (a[i][j] == 9) {
				shark.y = i, shark.x = j, shark.time = 0;
				shark_size = 2, shark_eat = 0;

				a[i][j] = 0; //상어가 있던 자리는 0으로 갱신
			}
		}
	}

	bool available = true; //해당 좌표에 먹을 수 있는 물고기가 존재하는가?

	while (available) {
		available = false;

		fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);

		visited[shark.y][shark.x] = 1; //상어 방문처리

		queue<Shark> q;
		q.push(shark);

		Shark candidates; //먹을 수 있는 가장 가까운 물고기의 정보 저장
		candidates.y = INT_MAX, candidates.time = -1; //init

		while (!q.empty()) {
			Shark cur = q.front(); q.pop();

			//가장 가까운 물고기를 이미 잡았다면 break
			if (candidates.time != -1 && candidates.time < cur.time) break;

			//cur의 좌표에 먹을 수 있는 물고기가 존재한다면
			if (a[cur.y][cur.x] != 0 && a[cur.y][cur.x] < shark_size) {
				available = true;

				//같은 거리라도 상 -> 좌 좌표 순서대로 먹는다
				if (candidates.y > cur.y || candidates.y == cur.y && candidates.x > cur.x) {
					candidates = cur; //해당 좌표가 현재 후보보다 좌상단에 있다면 후보 변경
				}
			}

			for (int dir = 0; dir < 4; dir++) {
				Shark ncur;

				ncur.y = cur.y + dy[dir];
				ncur.x = cur.x + dx[dir];
				ncur.time = cur.time + 1;

				if (ncur.y < 0 || ncur.y >= n || ncur.x < 0 || ncur.x >= n) continue;

				if (!visited[ncur.y][ncur.x] && a[ncur.y][ncur.x] <= shark_size) {
					visited[ncur.y][ncur.x] = 1;
					q.push(ncur);
				}
			}
		}

		//cur의 좌표에 먹을 수 있는 물고기가 존재한다면
		if (available) {
			shark = candidates; //최종 선택된 후보를 shark의 좌표로 갱신
			shark_eat++;

			if (shark_eat == shark_size) {
				shark_size++;
				shark_eat = 0;
			}

			a[shark.y][shark.x] = 0; //상어가 있던 자리는 0으로 갱신
		}
	}

	cout << shark.time;

	return 0;
}
