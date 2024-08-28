#include<iostream>
#include<cstring> //memcpy, memset
using namespace std;

int n;
int ret = -1;

struct Board {
	int a[21][21];

	void rotate() {
		int temp[21][21];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = a[n - j - 1][i];
			}
		}

		memcpy(a, temp, sizeof(temp));

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

		for (int i = 0; i < n; i++) {
			bool flag = false; //combinalbe flag
			int c = 0; //moving variable

			for (int j = 0; j < n; j++) {
				if (a[i][j] == 0) continue;

				if (flag && (a[i][j] == temp[i][c - 1])) {
					temp[i][c - 1] += a[i][j]; //flag = true였던 좌표 temp[i][c - 1] 기준으로 밀고 합치기
					flag = false; //합쳤다면 해당 좌표에 대해서 flag = false
				}
				else {
					temp[i][c] = a[i][j]; //밀기
          				flag = true; //현재 temp[i][c]에 대해서 합칠 수 있는 flag = true
					c++;
				}
			}

			//더 이상 참조할 j가 없다면 단독으로 temp를 완성
			while (c < n) {
				temp[i][c] = 0;
				c++;
			}
		}

		memcpy(a, temp, sizeof(temp));

		return;
	}
};

void dfs(Board c, int here) {
	if (here == 5) {
		c.get_max();

		return;
	}

  	//15683번 <감시> 문제처럼 단순한 방문 처리 복구가 아닌 배열의 값 자체를 바꾸고 활용하는 행위이므로 원상 복구는 사실상 불가능하다
  	//메모리가 충분하므로 복제된 d를 계속 생성 후 dfs를 돌리는 방법 선택. 4x5 개의 Board가 생성된다
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c.a[i][j];
		}
	}

	dfs(c, 0);

	cout << ret;

	return 0;
}
