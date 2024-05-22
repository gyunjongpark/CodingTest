#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m;
string s;
char a[MAX][MAX];
int visited[MAX][MAX];

void bfs(int y, int x) {
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y,x });

	pair<int, int> pi;

	while (q.size()) {
		pi = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = pi.first + dy[i];
			int nx = pi.second + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (a[ny][nx] == '1' && !visited[ny][nx]) {
				visited[ny][nx] = visited[pi.first][pi.second] + 1;
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
	bfs(0, 0); //1,1

	cout << visited[n - 1][m - 1];

	return 0;
}
