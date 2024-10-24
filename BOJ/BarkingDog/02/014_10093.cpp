#include<iostream>
using namespace std;
typedef unsigned long long ll;

ll a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> a >> b;

	if (a > b) {
		swap(a, b); //swap은 참조자 기반 함수이다
	}

	if (a == b || b - a == 1) cout << 0;
	else {
		cout << b - a - 1 << '\n';

		for (ll i = a + 1; i < b; i++) {
			cout << i << ' ';
		}
	}

	return 0;
}
