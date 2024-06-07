#include<iostream>
using namespace std;
const int INF = 1e6;
int ret = INF, n, m, h, j, a, b;
bool visited[31][11];

bool check() { //모든 번호가 자기 번호에 맞게 내려왔는지 확인
	for (int i = 1; i <= n; i++) {
		int start = i;
		for (int j = 1; j <= h; j++) {
			//j번 점선 위치에서 start와 start+1 사이가 연결되어 있다면
			if (visited[j][start]) start++;

			//j번 점선 위치에서 start-1과 start 사이가 연결되어 있다면
			else if (visited[j][start - 1]) start--;
		}
		//start 위치가 바뀌었다면 false 반환
		if (start != i) return false;
	}
	//start가 처음 i 그대로라면 true 반환
	return true;
}

void dfs(int here, int cnt) {
	if (cnt > 3 || cnt > ret) return;

	if (check()) {
		ret = min(ret, cnt);

		return;
	}

	for (int i = here; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1])
				continue;

			visited[i][j] = 1;
			dfs(i, cnt + 1);
			visited[i][j] = 0;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> h;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		visited[a][b] = 1;
	}
	dfs(1, 0);

	int result = (ret == INF ? -1 : ret);
	cout << result;

	return 0;
}
