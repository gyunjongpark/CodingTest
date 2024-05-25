#include<iostream>
#include<vector>
#define MAX 65
using namespace std;

vector<pair<int, int>> virusList, wallList;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
bool visited[MAX][MAX];
int n, m, a[MAX][MAX];

void dfs(int y, int x) {
	visited[y][x] = 1; //방문 처리로 오염시키기

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (a[ny][nx] == 0 && !visited[ny][nx]) { //오염 가능한 지역 dfs
			dfs(ny, nx);
		}
	}

	return;
}

int go() {
	for (pair<int, int> virus : virusList) {
		dfs(virus.first, virus.second); //바이러스 시작점에서부터 dfs 시작
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && !visited[i][j]) cnt++; //오염되지 않은 지역 count
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
			if (a[i][j] == 0) wallList.push_back({ i,j });
			else if (a[i][j] == 2) virusList.push_back({ i,j });
		}
	}

	int ret = -1; //max count
	for (int i = 0; i < wallList.size(); i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0); //방문 초기화

				visited[wallList[i].first][wallList[i].second] = 1;
				visited[wallList[j].first][wallList[j].second] = 1;
				visited[wallList[k].first][wallList[k].second] = 1;

				ret = max(ret, go());

				visited[wallList[i].first][wallList[i].second] = 0;
				visited[wallList[j].first][wallList[j].second] = 0;
				visited[wallList[k].first][wallList[k].second] = 0;
			}
		}
	}
	cout << ret;

	return 0;
}
