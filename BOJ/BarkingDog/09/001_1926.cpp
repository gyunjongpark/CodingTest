#include<iostream>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, maxVal, ret, a[501][501];
bool visited[501][501];

int bfs(int y, int x) {
	visited[y][x] = 1;

	queue<pair<int, int>> q;
	q.push({ y,x });

	int size = 1; //그림의 넓이 계산

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (a[ny][nx] == 1 && !visited[ny][nx]) {
				visited[ny][nx] = 1;
				q.push({ ny, nx });

				size++;
			}
		}
	}

	return size;
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
				maxVal = max(maxVal, bfs(i, j));
				ret++;
			}
		}
	}

	cout << ret << '\n';
	cout << maxVal;

	return 0;
}
