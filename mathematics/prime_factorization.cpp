#include<iostream>
#include<cmath> //sqrt
using namespace std;

void prime_factorization(int n) { //O(sqrt(N))
	int x = n; //소인수 분해를 위한 변수 x 선언
	for (int i = 2; i <= (int)sqrt(n); i++) {
		while (x % i == 0) {
			cout << i << '\n'; //while문에 의해 소수인 i만 출력된다
			x /= i;
		}
	}

	//유일하게 sqrt(n)보다 큰 마지막 소인수가 있다면 출력
	if (x != 1) cout << x;

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
