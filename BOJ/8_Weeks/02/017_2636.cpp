#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, a[101][101], ret;
bool visited[101][101];
vector<pair<int, int>> cheese_list;

void bfs(int y, int x) {
	visited[y][x] = true;

	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		if (a[cur.first][cur.second] == 1) { //치즈
			visited[cur.first][cur.second] == true;
			cheese_list.push_back({ cur.first,cur.second });
		}
		else { //공기
			for (int i = 0; i < 4; i++) {
				int ny = cur.first + dy[i];
				int nx = cur.second + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

				if (!visited[ny][nx]) {
					visited[ny][nx] = true;
					q.push({ ny,nx }); //공기일 경우에만 in-queue
				}
			}
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
		fill(&visited[0][0], &visited[0][0] + 101 * 101, false);
		cheese_list.clear();

		bfs(0, 0); //판의 가장자리에는 치즈가 놓여 있지 않다

		int cnt = cheese_list.size(); //치즈조각이 놓여 있는 칸의 개수

		for (pair<int, int> c : cheese_list) {
			a[c.first][c.second] = 0; //치즈 녹이기
		}

		ret++; //녹인 횟수 증가

		bool flag = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1) {
					flag = true;
					break;
				}
			}

			if (flag) break;
		}

		if (!flag) {
			cout << ret << '\n' << cnt;
			break;
		}
	}

	return 0;
}
