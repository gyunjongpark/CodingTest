#include<iostream>
#define MAX 101
using namespace std;

int n, m;
string s;
int a[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'c') a[i][j] = 0; //구름
			else a[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) { //현재 구름이 있는 경우
				int cnt = 1;
				while (a[i][j + 1] == -1) { //다음 칸에 구름이 없을 경우 동쪽으로 이동
					a[i][j + 1] = cnt;
					cnt++, j++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
