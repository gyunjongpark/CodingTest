#include<iostream>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
bool visited[101][101], a[101][101];
int n, m, cnt, ret;
vector<pair<int, int>> v;

void dfs(int y, int x) {
	visited[y][x] = true;

	if (a[y][x] == 1) {
		v.push_back({ y,x }); // 녹일 치즈 저장
		return; // 치즈인 경우 본인만 방문하고 저장 후 return
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

		if (!visited[ny][nx]) {
			dfs(ny, nx);
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
		}
	}

	while (true) {
		fill(&visited[0][0], &visited[0][0] + 101 * 101, false); // init
		v.clear(); // 녹일 치즈 초기화

		dfs(0, 0); // 첫 좌표부터 dfs 시작

		for (pair<int, int> i : v) {
			a[i.first][i.second] = 0; // 치즈 녹이기
		}

		ret = v.size(); // 녹인 치즈의 개수
		cnt++; // 녹인 횟수 count

		bool flag = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j]) flag = true; // 녹일 치즈가 남아있다면 true
			}
		}
		if (!flag) break; // 더 이상 녹일 치즈가 없다면 break
	}

	cout << cnt << '\n' << ret;

	return 0;
}