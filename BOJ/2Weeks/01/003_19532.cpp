#include<iostream>
using namespace std;

int a, b, c, d, e, f;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c >> d >> e >> f;

	for (int y = -999; y <= 999; y++) {
		for (int x = -999; x <= 999; x++) {
			if (a * x + b * y == c && d * x + e * y == f) {
				cout << x << ' ' << y;
			}
		}
	}

	return 0;
}