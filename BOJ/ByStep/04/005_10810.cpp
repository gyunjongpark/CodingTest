#include<iostream>
using namespace std;

int a[101], n, m, i, j, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int cnt = 0; cnt < m; cnt++) {
		cin >> i >> j >> k;

		for (int val = i; val <= j; val++) {
			a[val] = k;
		}
	}

	for (int cnt = 1; cnt <= n; cnt++) {
		cout << a[cnt] << ' ';
	}

	return 0;
}
