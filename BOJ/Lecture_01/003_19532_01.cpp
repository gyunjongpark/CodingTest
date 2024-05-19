#include<iostream>
using namespace std;

int a, b, c, d, e, f;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c >> d >> e >> f;

  //brute force
	for (int i = -999; i <= 999; i++) {
		for (int j = -999; j <= 999; j++) {
			if (a * i + b * j == c && d * i + e * j == f) {
				cout << i << ' ' << j;
				break;
			}
		}
	}

	return 0;
}
