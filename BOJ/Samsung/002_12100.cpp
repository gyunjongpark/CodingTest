#include<iostream>
using namespace std;

int n, ret;

struct Board {
	int a[21][21];

	void rotate() {
		int temp[21][21];

		for (int i = 0; i < n; i++) { //열 c
			for (int j = 0; j < n; j++) { //행 r
				temp[i][j] = a[n - j - 1][i]; //시계방향으로 회전. (c, r) = (r - j - 1, c)
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = temp[i][j];
			}
		}

		return;
	}

	void get_max() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ret = max(ret, a[i][j]);
			}
		}

		return;
	}

	void pushing_blocks() {
		int temp[21][21];

		for (int i = 0; i < n; i++) { //행
			bool flag = false;
			int c = 0;

			for (int j = 0; j < n; j++) { //열
				if (a[i][j] == 0) continue;

				if (flag && (a[i][j] == temp[i][c - 1])) {
					temp[i][c - 1] += a[i][j]; //밀고 합치기
					flag = false; //한 번 합쳤다면 false
				}
				else {
					temp[i][c] = a[i][j]; //밀기
					flag = true; //합칠 수 있는 flag를 다시 true
					c++;
				}
			}

			//더 이상 참조할 j가 없다면 단독으로 temp 완성
			while (c < n) {
				temp[i][c] = 0;
				c++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = temp[i][j];
			}
		}

		return;
	}
};

void dfs(Board c, int here) {
	if (here == 5) {
		c.get_max();
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		Board d = c;

		d.pushing_blocks();
		
		dfs(d, here + 1);

		c.rotate();
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	Board c;

	for (int i = 0; i < n; i++) { //행 r
		for (int j = 0; j < n; j++) { //열 c
			cin >> c.a[i][j];
		}
	}

	dfs(c, 0);

	cout << ret;

	return 0;
}
