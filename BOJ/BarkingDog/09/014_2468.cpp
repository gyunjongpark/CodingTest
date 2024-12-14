#include<iostream>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, ny, nx, a[101][101];
bool visited[101][101];

void dfs(int y, int x, int k) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];

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

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	int ret = 1; //안전한 영역의 최대 개수

	//지역의 높이와 비가 내리는 양의 높이는 1이상 100 이하의 정수
	//두 수가 같을 때 아무 지역도 잠기지 않으므로 최소 갯수는 1이다
	for (int k = 1; k <= 100; k++) {
		int cnt = 0;

		fill(&visited[0][0], &visited[0][0] + 101 * 101, false);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > k && !visited[i][j]) {
					dfs(i, j, k);
					cnt++;
				}
			}
		}

		ret = max(ret, cnt);
	}

	cout << ret;

	return 0;
}
