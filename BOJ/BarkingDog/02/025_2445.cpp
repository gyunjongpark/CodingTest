#include<iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << '*';
		}

		for (int j = 0; j < (n - 1 - i) * 2; j++) {
			cout << ' ';
		}

		for (int j = 0; j <= i; j++) {
			cout << '*';
		}

		cout << '\n';
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			cout << '*';
		}

		for (int j = 0; j < (i + 1) * 2; j++) {
			cout << ' ';
		}

		for (int j = 0; j < n - 1 - i; j++) {
			cout << '*';
		}

		cout << '\n';
	}

	return 0;
}