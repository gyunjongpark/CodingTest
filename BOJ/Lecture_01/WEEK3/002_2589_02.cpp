#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#define MAX 51
using namespace std;

string s, a[MAX][MAX];
vector<pair<int, int>> Land;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, ypos, xpos, visited[MAX][MAX]; //bfs이므로 int형 visitied

void bfs(int y, int x) {
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (q.size()) {
		tie(ypos, xpos) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = ypos + dy[i];
			int nx = xpos + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (a[ny][nx] == "L" && !visited[ny][nx]) {
				visited[ny][nx] = visited[ypos][xpos] + 1;
				q.push({ ny,nx });
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
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == "L") {
				Land.push_back({ i,j });
			}
		}
	}

	int maxTime = -1;
	for (pair<int, int> Land1 : Land) {
		fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0);
		bfs(Land1.first, Land1.second);

		for (pair<int, int> Land2 : Land) {
			maxTime = max(maxTime, visited[Land2.first][Land2.second]);
		}
	}
	cout << maxTime-1;

	return 0;
}
