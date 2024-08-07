#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, k, sy, sx, ey, ex, a[101][101];
bool visited[101][101];
vector<int> v;

int dfs(int y, int x) {
	visited[y][x] = 1;
	int ret = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
		if (a[ny][nx] == 0 && !visited[ny][nx]) {
			ret += dfs(ny, nx);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n >> k;

	while (k--) {
		cin >> sx >> sy >> ex >> ey;

		for (int i = sy; i < ey; i++) {
			for (int j = sx; j < ex; j++) {
				a[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0 && !visited[i][j]) {
				v.push_back(dfs(i, j));
			}
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';
	for (int i : v) cout << i << ' ';

	return 0;
}
