#include<iostream>
#include<vector>
#include<cmath> //sqrt
using namespace std;

unsigned int n, t;

bool checkPrime(unsigned int num) {
	if (num <= 1) return 0;
	for (unsigned int i = 2; i <= (unsigned int)sqrt(num); i++) {
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
