#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
bool visited[101][101], board[101][101];
int n, m, ret;
vector<pair<int, int>> v; //녹일 치즈들의 좌표 저장

void bfs(int y, int x) {
	visited[y][x] = true;

	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		if (board[cur.first][cur.second] == 1) {
			v.push_back({ cur.first,cur.second });
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			//치즈인지 여부와 관계없이 일단 탐색
			if (!visited[ny][nx]) {
				visited[ny][nx] = true;
				bfs(ny, nx);
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
			cin >> board[i][j];
		}
	}

	while (true) {
		//초기화
		fill(&visited[0][0], &visited[0][0] + 101 * 101, false);
		v.clear();

		//녹일 치즈 구하기. v에 치즈 좌표 저장
		bfs(0, 0);

		int cnt = v.size(); //녹이기 직전 치즈의 양

		//치즈 녹이기
		for (pair<int, int> i : v) {
			board[i.first][i.second] = 0;
		}

		ret++; //녹인 횟수 증가

		bool flag = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1) {
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
