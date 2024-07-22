#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> virusList, wallList;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
bool visited[10][10];
int n, m, a[10][10];

void dfs(int y, int x) {
	visited[y][x] = 1; // 방문 처리로 바이러스 퍼뜨리기

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

// visited = 1인 경우는 벽이거나 바이러스가 퍼져 오염된 지역을 의미한다
int go() {
	for (pair<int, int> virus : virusList) {
		dfs(virus.first, virus.second); // 바이러스 퍼뜨리기
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && !visited[i][j]) cnt++; // 오염되지 않았다면
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

			if (a[i][j] == 0) wallList.push_back({ i,j }); // 벽이 될 가능성이 있는 좌표
			else if (a[i][j] == 2) virusList.push_back({ i,j }); // 바이러스가 있는 좌표
		}
	}

	int maxVal = -1;

	for (int i = 0; i < wallList.size(); i++) {
		for (int j = i + 1; j < wallList.size(); j++) {
			for (int k = j + 1; k < wallList.size(); k++) {
				fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);

				// 방문처리로 벽 세우기
				visited[wallList[i].first][wallList[i].second] = 1;
				visited[wallList[j].first][wallList[j].second] = 1;
				visited[wallList[k].first][wallList[k].second] = 1;

				maxVal = max(maxVal, go());

				// 원상 복구
				visited[wallList[i].first][wallList[i].second] = 0;
				visited[wallList[j].first][wallList[j].second] = 0;
				visited[wallList[k].first][wallList[k].second] = 0;
			}
		}
	}
	cout << maxVal;

	return 0;
}
