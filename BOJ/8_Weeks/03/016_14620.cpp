#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, a[11][11];
bool visited[11][11];
int ret = INT_MAX;
string s;

void eraseFlower(int y, int x) {
	visited[y][x] = false;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		visited[ny][nx] = false;
	}

	return;
}

int bloomFlower(int y, int x) {
	visited[y][x] = true;

	int ret = a[y][x];

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		visited[ny][nx] = true;
		ret += a[ny][nx];
	}

	return ret;
}

bool check(int y, int x) {
	if (visited[y][x]) return false;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) return false;
		if (visited[ny][nx]) return false;
	}

	return 1;
}

void dfs(int cnt, int cur) {
	if (cnt == 3) {
		ret = min(ret, cur);
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check(i, j)) {
				dfs(cnt + 1, cur + bloomFlower(i, j));
				eraseFlower(i, j);
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	dfs(0, 0);

	cout << ret;

	return 0;
}
