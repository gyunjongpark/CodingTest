#include<iostream>
#include<climits> //INT_MAX
using namespace std;

int n, m, h, j, a, b, result;
int ret = INT_MAX;
bool visited[31][11];

bool check() { //모든 번호가 자기 번호에 맞게 내려오는지 확인
	for (int i = 1; i <= n; i++) { //열(줄)별로 조사
		int start = i;

		for (int j = 1; j <= h; j++) { //j가 h까지 조사하면서 내려오게 된다

			//j행에서 start와 start + 1 사이가 연결되어 있다면
			if (visited[j][start]) start++;

			//else if. j행에서 start와 start - 1 사이가 연결되어 있다면
			else if (start >= 2 && visited[j][start - 1]) start--;
		}

		if (start != i) return false; //start 위치가 바뀌었다면 false 반환
	}

	return true; //그대로라면 true 반환
}

void dfs(int here, int cnt) {
	if (here > h || cnt > 3) return; //가로줄 범위를 넘어섰거나, 필요 가로선이 3개가 넘어간다면 return

	if (check()) { //조작 가능한지 확인
		ret = min(ret, cnt);
		return;
	}

	for (int i = here; i <= h; i++) { //행마다 하나의 가로선이 추가된다
		for (int j = 1; j < n; j++) {

			//j열에 이미 가로선이 있다면
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;

			visited[i][j] = 1; //가로선 추가

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

	for (int i = 0; i < m; i++) { //주어진 m개의 가로선 입력
		cin >> a >> b;
		visited[a][b] = 1; //a행에서 b -> b + 1 열로 가는 가로선을 표현한다
	}

	dfs(1, 0); //1번 가로줄, 횟수는 0부터 시작

	result = (ret == INT_MAX ? -1 : ret); //조작이 불가능한 경우, 3보다 큰 경우

	cout << result;

	return 0;
}
