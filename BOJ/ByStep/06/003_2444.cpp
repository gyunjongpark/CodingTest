#include<iostream>
using namespace std;

int n;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			cout << ' ';
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			cout << '*';
		}
		cout << '\n';
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << ' ';
		}
		for (int j = 0; j < (n - 2 - i) * 2 + 1; j++) {
			cout << '*';
		}
		cout << '\n';
	}

	return 0;
}
