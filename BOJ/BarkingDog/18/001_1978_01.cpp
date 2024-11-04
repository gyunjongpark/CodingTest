#include<iostream>
using namespace std;

int n, temp, ret;

bool check(int n) {
	if (n <= 1) return false;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (check(temp)) ret++;
	}

	cout << ret;

	return 0;
}
