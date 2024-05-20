#include<iostream>
#include<cmath>
using namespace std;

int a, n, ret;

/*
제곱근보다 큰 소수는 반드시 제곱근보다 작은 소수와 짝을 이루므로
제곱근 이상의 소수로 나누는 검사 행위는 의미가 없음.
이미 참이기 때문이다.
*/

bool check(int n) {
	if (n == 1) return 0;
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) return 0;
	}
  
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (check(a)) ret++;
	}
  
	cout << ret;

	return 0;
}
