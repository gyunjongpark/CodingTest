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

	queue<info> q;
	q.push(start); //queue에 ry,rx,by,bx,0 입력

	int ret = -1;

	while (!q.empty()) {
		info cur = q.front(); q.pop();

		if (cur.cnt > 10) break;

		if (a[cur.ry][cur.rx] == 'O' && a[cur.by][cur.bx] != 'O') { //빨간색 사탕만 뺐다면
			ret = cur.cnt;
			break;
		}

		for (int dir = 0; dir < 4; dir++) {
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
					if (a[nry][nrx] == '#') { //벽을 만났다면
						nry -= dy[dir];
						nrx -= dx[dir];
					}
					break;
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
					break;
				}
			}

			if (nry == nby && nrx == nbx) { //두 구슬이 겹치는 경우
				if (a[nry][nrx] != 'O') { //출구가 아닌 경우
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

	start.cnt = 0;

	ret = bfs();

	cout << ret;

	return 0;
}
