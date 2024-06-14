#include<iostream>
#define MAX 104
using namespace std;

int a[MAX], n, m, i, j, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int cnt = 1; cnt <= n; cnt++) {
		a[cnt] = cnt;
	}

	for (int cnt = 0; cnt < m; cnt++) {
		cin >> i >> j;
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	for (int cnt = 1; cnt <= n; cnt++) {
		cout << a[cnt] << ' ';
	}

	return 0;
}
