#include<iostream>
#include<queue>
using namespace std;

struct info {
	int ry, rx, by, bx, cnt;
};
info start;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
bool visited[11][11][11][11];
int n, m;
int ret = -1;
char a[11][11];
string s;

void bfs() {
	visited[start.ry][start.rx][start.by][start.bx] = 1;
	
	queue<info> q;
	q.push(start);

	while (!q.empty()) {
		info cur;
		cur = q.front(); q.pop();

		//종료 조건 1
		if (cur.cnt > 10) break;

		//종료 조건 2
		if (a[cur.ry][cur.rx] == 'O' && a[cur.by][cur.bx] != 'O') {
			ret = cur.cnt;
			break;
		}

		//현재 좌표를 기준으로 검사를 진행한다
		//일반적인 ny = y + dy[i]로는 y가 구멍일지라도 반복문이 진행되므로 논리에 맞지 않는다
		for (int dir = 0; dir < 4; dir++) {
			int nry = cur.ry;
			int nrx = cur.rx;
			int nby = cur.by;
			int nbx = cur.bx;

			//빨간 구슬
			while (true) {
				//벽, 구멍이 아니라면 해당 방향으로 계속 진행
				if (a[nry][nrx] != '#' && a[nry][nrx] != 'O') {
					nry += dy[dir];
					nrx += dx[dir];
				}
				else { //벽 또는 구멍이라면
					if (a[nry][nrx] == '#') { //그 중 벽이라면
						nry -= dy[dir];
						nrx -= dx[dir];
						break; //한칸 뒤로 돌린 후 break
					}

					break; //구멍이라면 그 위치에서 break
				}
			}

			//파란 구슬
			while (true) {
				//벽, 구멍이 아니라면 해당 방향으로 계속 진행
				if (a[nby][nbx] != '#' && a[nby][nbx] != 'O') {
					nby += dy[dir];
					nbx += dx[dir];
				}
				else { //벽 또는 구멍이라면
					if (a[nby][nbx] == '#') { //그 중 벽이라면
						nby -= dy[dir];
						nbx -= dx[dir];
						break; //한칸 뒤로 돌린 후 break
					}

					break; //구멍이라면 그 위치에서 break
				}
			}

			if (nry == nby && nrx == nbx) { //두 구슬이 겹쳤다면
				if (a[nry][nrx] != 'O') { //겹쳤는데 구멍이 아닌 경우
					int r_dist = abs(nry - cur.ry) + abs(nrx - cur.rx);
					int b_dist = abs(nby - cur.by) + abs(nbx - cur.bx);

					//거리가 더 먼 구슬을 한 칸 더 뒤로 이동
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

			//방문한 좌표는 queue에 다시 집어넣지 않는다
			if (!visited[nry][nrx][nby][nbx]) {
				visited[nry][nrx][nby][nbx] = 1;

				q.push({ nry,nrx,nby,nbx,cur.cnt + 1 });
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];

			if (a[i][j] == 'R') {
				start.ry = i;
				start.rx = j;
			}

			if (a[i][j] == 'B') {
				start.by = i;
				start.bx = j;
			}
		}
	}

	bfs();

	cout << ret;

	return 0;
}
