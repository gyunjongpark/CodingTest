#include<iostream>
#include<vector>
using namespace std;

unsigned int n, t; //정수 n(0 ≤ n ≤ 4 * 10^9)가 주어졌을 때

bool checkPrime(unsigned int num) { // 4 * 10^9
	if (num <= 1) return 0;

	for (unsigned int i = 2; i * i <= num; i++) {
		if (num % i == 0) return 0;
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n;

		while (true) {
			if (checkPrime(n)) break;
			n++;
		}

		cout << n << '\n';
	}

	return 0;
}
