#include<iostream>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
bool visited[11][11][11][11]; //ry,rx,by,bx
int n, m, ret;
char a[11][11];
string s;

struct info { //bfs에서 queue의 자료형을 정의하기 위한 구조체
	int ry, rx, by, bx, cnt;
};

info start; //info형 변수 start


int bfs() {
	visited[start.ry][start.rx][start.by][start.bx] = 1;

	queue<info> q; //원소가 5개이므로 pair의 집합이 아닌 struct로 정의한다
	q.push(start); //queue에 {ry,rx,by,bx,0} 입력

	int ret = -1;

	while (!q.empty()) {
		info cur = q.front(); q.pop();

		if (cur.cnt > 10) break;

		if (a[cur.ry][cur.rx] == 'O' && a[cur.by][cur.bx] != 'O') { //빨간색 사탕만 빼냈다면
			ret = cur.cnt;
			break;
		}

		for (int dir = 0; dir < 4; dir++) {
			//현재 좌표 저장
			//두 개의 while문을 거치면서 다음 목적지의 좌표를 반환
			int nry = cur.ry;
			int nrx = cur.rx;
			int nby = cur.by;
			int nbx = cur.bx;

			while (true) {
				if (a[nry][nrx] != '#' && a[nry][nrx] != 'O') {
					nry += dy[dir];
					nrx += dx[dir];
				}
				else {
					if (a[nry][nrx] == '#') {
						nry -= dy[dir];
						nrx -= dx[dir];
					}

					break; //구멍이거나 벽이라면 더 이상 진행하지 않고 break
				}
			}

			while (true) {
				if (a[nby][nbx] != '#' && a[nby][nbx] != 'O') {
					nby += dy[dir];
					nbx += dx[dir];
				}
				else {
					if (a[nby][nbx] == '#') {
						nby -= dy[dir];
						nbx -= dx[dir];
					}

					break; //구멍이거나 벽이라면 더 이상 진행하지 않고 break
				}
			}

			if (nry == nby && nrx == nbx) { //두 구슬이 겹치는 경우
				if (a[nry][nrx] != 'O') { //구멍이 아닌 경우
					int r_dist = abs(nry - cur.ry) + abs(nrx - cur.rx);
					int b_dist = abs(nby - cur.by) + abs(nbx - cur.bx);

					if (r_dist > b_dist) {
						nry -= dy[dir];
						nrx -= dx[dir];
					}
					else {
						nby -= dy[dir];
						nbx -= dx[dir];
					}
				}
			}

			if (!visited[nry][nrx][nby][nbx]) {
				visited[nry][nrx][nby][nbx] = 1;

				q.push({ nry,nrx,nby,nbx,cur.cnt + 1 });
			}
		}

	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}

	start.cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'R') {
				start.ry = i, start.rx = j;
			}

			if (a[i][j] == 'B') {
				start.by = i, start.bx = j;
			}
		}
	}

	ret = bfs();

	cout << ret;

	return 0;
}
