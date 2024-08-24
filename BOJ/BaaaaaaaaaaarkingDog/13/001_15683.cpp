#include<iostream>
#include<vector>
#include<tuple> //tie
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, a[10][10];
int ret = 101;
vector<pair<int, int>> cctv_list;

vector<pair<int, int>> spread(int cctv_cnt, int dir) {
	vector<pair<int, int>> ret;

	int i, j;
	tie(i, j) = cctv_list[cctv_cnt];

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

				//벽만 아니라면 cctv는 끝까지 퍼진다
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

void dfs(int cctv_cnt) {
	if (cctv_cnt == cctv_list.size()) { //모든 cctv를 조사했다면
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) cnt++; //사각지대 계산
			}
		}

		ret = min(ret, cnt); //최솟값 갱신

		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		vector<pair<int, int>> spreaded_area = spread(cctv_cnt, dir);
		dfs(cctv_cnt + 1);

		for (pair<int, int> s : spreaded_area) { //원상 복구
			a[s.first][s.second] = 0;
		}
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
				cctv_list.push_back({ i,j });
			}
		}
	}

	dfs(0); //0번째 cctv부터 dfs

	cout << ret;

	return 0;
}
