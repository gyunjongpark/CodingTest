#include<iostream>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
vector<pair<int, int>> virusList, wallList;
int n, m, a[10][10];
bool visited[10][10];

void dfs(int y, int x) {
	visited[y][x] = 1; //spread

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

		if (a[ny][nx] == 0 && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}

	return;
}

int check_area() {
	for (pair<int, int> virus : virusList) {
		dfs(virus.first, virus.second);
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && !visited[i][j]) cnt++;
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];

			if (a[i][j] == 0) wallList.push_back({ i,j }); //벽이 될 가능성이 있는 좌표
			else if (a[i][j] == 2) virusList.push_back({ i,j }); //바이러스가 있는 좌표
		}
	}

	int maxVal = 0;

	for (int i = 0; i < wallList.size(); i++) {
		for (int j = i + 1; j < wallList.size(); j++) {
			for (int k = j + 1; k < wallList.size(); k++) {
        
				//방문 처리 초기화(세웠던 벽 + 방문 초기화)
				fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);

				//방문 처리로 벽 세우기
				visited[wallList[i].first][wallList[i].second] = 1;
				visited[wallList[j].first][wallList[j].second] = 1;
				visited[wallList[k].first][wallList[k].second] = 1;

				maxVal = max(maxVal, check_area());
			}
		}
	}

	cout << maxVal;

	return 0;
}
