#include<iostream>
using namespace std;

struct Shark {
	int y, x, d;
	int priority_dir[4][4]; //상하좌우마다 우선시 되는 방향
	bool isDead;
};
Shark sharks[400];

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
int n, m, k, board[20][20][3];
int ret = -1;

void go() {
	int t = 0;
	int disappered = 0;

	while (t <= 1000) {
		if (disappered == m - 1) break; //1번 상어만 남았다면 break

		t++;

		int temp_board[20][20][3];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp_board[i][j][0] = board[i][j][0]; //상어 번호 복사
				temp_board[i][j][2] = board[i][j][2]; //냄새 지속 시간 복사

				if (temp_board[i][j][2] > 0) { //냄새가 있다면
					temp_board[i][j][2]--; //시간이 지났으므로 냄새가 줄어든다
					temp_board[i][j][1] = board[i][j][1]; //냄새의 주인인 상어 번호 복사
				}
			}
		}

		for (int i = 0; i < m; i++) {
			if (sharks[i].isDead == true) continue;

			int cy = sharks[i].y;
			int cx = sharks[i].x;
			int cd = sharks[i].d;

			bool flag = false;

			for (int d = 0; d < 4; d++) {
				int nd = sharks[i].priority_dir[cd][d];

				int ny = cy + dy[nd];
				int nx = cx + dx[nd];

				//범위를 벗어나거나 냄새가 있는 칸이라면 continue (이동 불가)
				if (ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx][2]) continue;
				else { //이동 가능하다면
					flag = true;
					temp_board[cy][cx][0] = 0;

					if (temp_board[ny][nx][0] == 0) {
						temp_board[ny][nx][0] = i + 1;
						temp_board[ny][nx][1] = i + 1;
						temp_board[ny][nx][2] = k;

						sharks[i].y = ny;
						sharks[i].x = nx;
						sharks[i].d = nd;
					}
					else {
						disappered++;
						sharks[i].isDead = true;
					}

					break;
				}
			}
			
			//for문을 전부 돌았지만 flag = false라면(범위를 벗어나거나 냄새가 있는 칸이라면)
			if (flag == false) {
				for (int d = 0; d < 4; d++) {
					int nd = sharks[i].priority_dir[cd][d];

					int ny = cy + dy[nd];
					int nx = cx + dx[nd];

					//범위를 벗어난다면 continue (이동 불가)
					//냄새가 있지만 본인 것이 아니라면 continue (이동 불가)
					if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;	
					if (board[ny][nx][2] && board[ny][nx][1] != i + 1) continue;
					else { //이동 가능하다면
						flag = true;
						temp_board[cy][cx][0] = 0;

						if (temp_board[ny][nx][0] == 0) {
							temp_board[ny][nx][0] = i + 1;
							temp_board[ny][nx][1] = i + 1;
							temp_board[ny][nx][2] = k;

							sharks[i].y = ny;
							sharks[i].x = nx;
							sharks[i].d = nd;
						}
						else {
							disappered++;
							sharks[i].isDead = true;
						}

						break;
					}					
				}
			}
		}

		if (disappered == m - 1) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j][0] = temp_board[i][j][0];
				board[i][j][1] = temp_board[i][j][1];
				board[i][j][2] = temp_board[i][j][2];
			}
		}
	}

	if (t <= 1000) ret = t;

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j][0]; //상어 번호

			if (board[i][j][0] != 0) { //상어라면
				int shark_idx = board[i][j][0] - 1; //인덱싱

				sharks[shark_idx].y = i;
				sharks[shark_idx].x = j;

				board[i][j][1] = board[i][j][0]; //냄새의 주인인 상어 번호
				board[i][j][2] = k; //냄새 지속 시간
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> sharks[i].d; //현재 방향
		sharks[i].d--; //인덱싱
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> sharks[i].priority_dir[j][k]; //현재 방향에 따른 우선순위 방향
				sharks[i].priority_dir[j][k]--; //인덱싱
			}
		}
	}

	go();

	cout << ret;

	return 0;
}
