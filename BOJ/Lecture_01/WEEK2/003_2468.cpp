#include<iostream>
#define MAX 101
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
bool visited[MAX][MAX];
int a[MAX][MAX], n;

void dfs(int y, int x, int k) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (a[ny][nx] > k && !visited[ny][nx]) {
			dfs(ny, nx, k);
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

	int k = 100, ret = 1;
	while (k--) {
		int cnt = 0;
		fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0);
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > k && !visited[i][j]) {
					dfs(i, j, k); cnt++;
				}
			}
		}
		ret = max(ret, cnt);
	}
	cout << ret;

	return 0;
}
