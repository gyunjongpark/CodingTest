#include<iostream>
#include<cstring> //memcpy, memset..?
#define MAX 21
using namespace std;

const int INF = -1e6;
int ret=INF, n;

struct Board {
	int a[MAX][MAX];

	void rotate() {
		int temp[MAX][MAX];

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

	void move() {
		int temp[MAX][MAX];

		for (int i = 0; i < n; i++) {
			bool flag = 0;
			int c = 0;
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 0) continue;

				if (flag && a[i][j] == temp[i][c-1]) {
					temp[i][c-1] *= 2;
					flag = 0;
				}
				else {
					temp[i][c] = a[i][j];
					c++;
					flag = 1;
				}
			}
			for (c = c; c < n; c++) {
				temp[i][c] = 0;
			}
		}
		memcpy(a, temp, sizeof(temp));
    
		return;
	}
};

void go(Board c, int here) {
	if (here == 5) {
		c.get_max();
    
		return;
	}
  
	for (int i = 0; i < 4; i++) {
		Board d = c;
		d.move();
		go(d, here + 1);
		c.rotate();
	}
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
	go(c, 0); // Board c, here 0

	cout << ret;
  
	return 0;
}
