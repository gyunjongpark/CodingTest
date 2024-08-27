#include<iostream>
#include<cmath> //sqrt
using namespace std;

void prime_factorization(int num) { //O(sqrt(N))
	for (int i = 2; i <= (int)sqrt(num); i++) {
		while (num % i == 0) {
			cout << i << '\n'; //while문에 의해 소수인 i만 출력된다
			num /= i;
		}
	}

	if (num != 1) cout << num; //유일하게 sqrt(n)보다 큰 마지막 소인수가 있다면 출력

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;

	prime_factorization(n);

	return 0;
}
