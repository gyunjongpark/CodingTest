#include<iostream>
using namespace std;
typedef unsigned long long ll;

int t, n, a[101];
ll ret;

int getGCD(int a, int b) {
	if (a == 0) return b;

	return getGCD(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t; //t <= 100

	while (t--) {
		cin >> n; //n <= 100

		fill(a, a + 101, 0);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		ll ret = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				ret += getGCD(a[i], a[j]);
			}
		}

		cout << ret << '\n';
	}

	return 0;
}
