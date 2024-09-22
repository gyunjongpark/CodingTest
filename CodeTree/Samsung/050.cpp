#include<iostream>
#include<climits> //INT_MAX
using namespace std;

int n, m, h, j, a, b, result;
int ret = INT_MAX;
bool visited[31][11];

bool check() { //모든 번호가 자기 번호에 맞게 내려오는지 확인
	for (int i = 1; i <= n; i++) {
		int start = i;

		for (int j = 1; j <= h; j++) {
			//j번 점선 위치에서 start와 start + 1 사이가 연결되어 있다면
			if (visited[j][start]) start++;

			//j번 점선 위치에서 start와 start - 1 사이가 연결되어 있다면
			else if (visited[j][start - 1]) start--;
		}

		if (start != i) return false; //start 위치가 바뀌었다면 false 반환
	}
	
	return true; //start가 처음 i 그대로라면 true 반환
}

void dfs(int here, int cnt) {
	if (here > h || cnt > 3) return;

	if (check()) {
		ret = min(ret, cnt);

		return;
	}

	for (int i = here; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
				
			visited[i][j] = 1; //메모리 유실 선 추가

			dfs(i, cnt + 1);

			visited[i][j] = 0; //원상 복구
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
		visited[a][b] = 1; //주어진 메모리 유실 선 입력
	}

	dfs(1, 0);

	result = (ret == INT_MAX ? -1 : ret); //불가능한 경우, 3보다 큰 경우

	cout << result;

	return 0;
}
