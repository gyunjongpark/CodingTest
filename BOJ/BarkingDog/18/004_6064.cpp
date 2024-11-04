#include<iostream>
using namespace std;

int n;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int go(int m, int n, int x, int y) {
	if (x == m) x = 0;
	if (y == n) y = 0;

	int l = lcm(m, n);

	for (int i = x; i <= l; i += m) {
		if (i == 0) continue;
		if (i % n == y) {
			return i;
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		int m, n, x, y;

		cin >> m >> n >> x >> y;
		cout << go(m, n, x, y) << '\n';
	}

	return 0;
}
