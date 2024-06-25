#include<iostream>
using namespace std;

int n, a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	a = n / 5;
	while (true) {
		if (a < 0) {
			cout << -1;
			return 0;
		}

		if ((n - a * 5) % 3 == 0) {
			b = (n - a * 5) / 3;
			break;
		}
		a--; //정확하게 나눌 수 없는 경우를 만들기 위해
	}
	cout << a + b;

	return 0;
}
