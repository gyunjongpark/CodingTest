#include<iostream>
using namespace std;

int n, a[130][130], ret_zero, ret_one;

void recur(int y, int x, int n) {
	if (n == 1) {
		if (a[y][x] == 0) {
			ret_zero++;
		}
		else if (a[y][x] == 1) {
			ret_one++;
		}

		return;
	}

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (a[y][x] != a[i][j]) {
				recur(y, x, n / 2);
				recur(y, x + n / 2, n / 2);
				recur(y + n / 2, x, n / 2);
				recur(y + n / 2, x + n / 2, n / 2);

				return;
			}
		}
	}

	if (a[y][x] == 0) {
		ret_zero++;
	}
	else if (a[y][x] == 1) {
		ret_one++;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	recur(0, 0, n);

	cout << ret_zero << '\n';
	cout << ret_one << '\n';

	return 0;
}