#include<iostream>
#include<vector>
#include<climits> //INT_MAX
#include<tuple> //tie
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, a[10][10];
int ret = INT_MAX;
vector<pair<int, int>> chess_list;

vector<pair<int, int>> move(int chess_cnt, int dir) {
	vector<pair<int, int>> ret;

	int i, j;
	tie(i, j) = chess_list[chess_cnt];

	if (a[i][j] == 1) {
		int y, x;
		tie(y, x) = { i,j };

		while (true) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
				if (a[ny][nx] == 0) {
					a[ny][nx] = 7;
					ret.push_back({ ny,nx });
				}

				//벽만 아니라면 말은 끝까지 이동한다
				y = ny;
				x = nx;
			}
			else break;
		}
	}
	else if (a[i][j] == 2) {
		for (int d = 0; d <= 2; d += 2) {
			int y, x;
			tie(y, x) = { i,j };

			while (true) {
				int ny = y + dy[(d + dir) % 4];
				int nx = x + dx[(d + dir) % 4];

				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
					if (a[ny][nx] == 0) {
						a[ny][nx] = 7;
						ret.push_back({ ny,nx });
					}

					y = ny;
					x = nx;
				}
				else break;
			}
		}
	}
	else if (a[i][j] == 3) {
		for (int d = 0; d < 2; d++) {
			int y, x;
			tie(y, x) = { i,j };

			while (true) {
				int ny = y + dy[(d + dir) % 4];
				int nx = x + dx[(d + dir) % 4];

				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
					if (a[ny][nx] == 0) {
						a[ny][nx] = 7;
						ret.push_back({ ny,nx });
					}

					y = ny;
					x = nx;
				}
				else break;
			}
		}
	}
	else if (a[i][j] == 4) {
		for (int d = 0; d < 3; d++) {
			int y, x;
			tie(y, x) = { i,j };

			while (true) {
				int ny = y + dy[(d + dir) % 4];
				int nx = x + dx[(d + dir) % 4];

				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
					if (a[ny][nx] == 0) {
						a[ny][nx] = 7;
						ret.push_back({ ny,nx });
					}

					y = ny;
					x = nx;
				}
				else break;
			}
		}
	}
	else if (a[i][j] == 5) {
		for (int d = 0; d < 4; d++) {
			int y, x;
			tie(y, x) = { i,j };

			while (true) {
				int ny = y + dy[(d + dir) % 4];
				int nx = x + dx[(d + dir) % 4];

				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
					if (a[ny][nx] == 0) {
						a[ny][nx] = 7;
						ret.push_back({ ny,nx });
					}

					y = ny;
					x = nx;
				}
				else break;
			}
		}
	}

	return ret;
}

void dfs(int chess_cnt) {
	if (chess_cnt == chess_list.size()) { //모든 말을 조사했다면
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) cnt++; //도달하지 못한 격자의 수 계산
			}
		}

		ret = min(ret, cnt); //최솟값 갱신

		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		vector<pair<int, int>> spreaded_area = move(chess_cnt, dir);

		dfs(chess_cnt + 1);

		for (pair<int, int> s : spreaded_area) a[s.first][s.second] = 0; //원상 복구
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];

			if (a[i][j] != 0 && a[i][j] != 6) {
				chess_list.push_back({ i,j });
			}
		}
	}

	dfs(0); //0번째 말부터 dfs

	cout << ret;

	return 0;
}
