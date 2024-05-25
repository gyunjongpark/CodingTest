#include<iostream>
#include<vector>
#define MAX 101
using namespace std;

bool visited[MAX][MAX], a[MAX][MAX];
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, cnt, ret;
vector<pair<int, int>> v;

void dfs(int y, int x) {
	visited[y][x] = 1;

	if (a[y][x] == 1) {
		v.push_back({ y,x }); //녹을 치즈 좌표 저장하기
		return; //dfs 중단하고 return
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (!visited[ny][nx]) { //배열 전체를 방문해서 1이라면 치즈 인식!
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
		fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0); //초기화
		v.clear(); //초기화

		dfs(0, 0); //0,0부터 탐색

		for (pair<int, int> i : v) { //치즈 녹이기
			a[i.first][i.second] = 0;
		}
		
		ret = v.size(); //녹인 치즈의 개수
		cnt++; // 녹인 횟수 count

		bool flag = 0; //반복문 탈출 조건
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j]) flag = 1; //녹일 치즈가 남아있다면 true
			}
		}
		if (!flag) break; //녹일 치즈가 없다면 break
	}
	cout << cnt << '\n' << ret;
	
	return 0;
}
