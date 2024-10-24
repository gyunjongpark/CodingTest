#include<iostream>
using namespace std;

int a[101], n, m, i, j, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int cnt = 1; cnt <= n; cnt++) {
		a[cnt] = cnt;
	}

	for (int cnt = 0; cnt < m; cnt++) {
		cin >> i >> j;
		swap(a[i], a[j]);
	}

	for (int cnt = 1; cnt <= n; cnt++) {
		cout << a[cnt] << ' ';
	}

	return 0;
}
