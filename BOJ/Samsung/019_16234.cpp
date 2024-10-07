#include<iostream>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, ret, l, r, sum, a[51][51];
bool visited[51][51];
vector<pair<int, int>> v;

void dfs(int y, int x) {
	visited[y][x] = true;

	v.push_back({ y,x });
	sum += a[y][x];

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

		int diff = abs(a[y][x] - a[ny][nx]);

		if (!visited[ny][nx] && l <= diff && diff <= r) {
			dfs(ny, nx);
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	while (true) {
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

		bool flag = false; //인구이동 발생 시 true

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				v.clear();
				sum = 0;

				if (!visited[i][j]) {
					dfs(i, j);

					if (v.size() == 1) continue; //본인만 포함되었다면(국경선이 공유되지 않음)
					else {
						for (pair<int, int> i : v) {
							a[i.first][i.second] = sum / v.size();
						}

						flag = true; //인구 이동 발생
					}
				}
			}
		}

		if (!flag) break;

		ret++;
	}

	cout << ret;

	return 0;
}
