#include<iostream>
#define MAX 1030
using namespace std;

int n, m, temp, s[MAX][MAX];
int a1, a2, b1, b2; // a는 행, b는 열

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + temp;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a1 >> b1 >> a2 >> b2;
		cout << s[a2][b2] - s[a2][b1 - 1] - s[a1 - 1][b2] + s[a1 - 1][b1 - 1] << '\n';
	}

	return 0;
}
