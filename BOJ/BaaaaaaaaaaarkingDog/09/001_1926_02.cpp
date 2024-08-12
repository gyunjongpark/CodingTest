#include<iostream>
#include<vector>
#include<algorithm> //max_element
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, ret, maxVal, a[501][501];
bool visited[501][501];
vector<int> v;

int dfs(int y, int x) {
	visited[y][x] = 1;
	
	int ret = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

		if (a[ny][nx] == 1 && !visited[ny][nx]) {
			ret += dfs(ny, nx);
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 && !visited[i][j]) {
				v.push_back(dfs(i, j));
				ret++;
			}
		}
	}

	if (v.empty()) maxVal = 0; //그림이 없을 경우
	else {
		maxVal = *(max_element(v.begin(), v.end()));
	}
	
	cout << ret << '\n';
	cout << maxVal;

	return 0;
}
