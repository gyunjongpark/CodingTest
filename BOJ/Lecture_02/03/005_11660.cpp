#include<iostream>
#define MAX 1034
using namespace std;

int n, m, temp, s[MAX][MAX];
int a1, a2, b1, b2; // a는 행, b는 열

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) { //0행과 0열은 0으로 비워둔 후 계산한다
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + temp;
		}
	}

	while(m--) {
		cin >> a1 >> b1 >> a2 >> b2;
		cout << s[a2][b2] - s[a2][b1 - 1] - s[a1 - 1][b2] + s[a1 - 1][b1 - 1] << '\n';
	}

	return 0;
}
