#include<iostream>
#include<string>
using namespace std;

int n;

void recur(int i, int j, int n) {
	if (j <= 2 * i) {
		if (n == 3 && !(i == 1 && j == 1)) {
			cout << '*';
		}
		else recur(i % (n / 2), j % n, n / 2);
	}
	else cout << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << string(n - i - 1, ' '); //string(갯수, char형 문자)

		for (int j = 0; j <= n + i; j++) {
			recur(i, j, n);
		}

		cout << '\n';
	}

	return 0;
}
