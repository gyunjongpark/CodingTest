#include<iostream>
using namespace std;

int a, t, s[4]; //쿼터, 다임, 니켈, 페니

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> a;

		s[0] = a / 25, a %= 25;
		s[1] = a / 10, a %= 10;
		s[2] = a / 5, a %= 5;
		s[3] = a;

		for (int a : s) cout << a << ' ';
		cout << '\n';
	}

	return 0;
}
