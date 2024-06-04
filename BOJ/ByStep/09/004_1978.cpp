#include<iostream>
#include<cmath>
using namespace std;

int a, n, ret;

/*
제곱근보다 큰 약수는 반드시 제곱근보다 작은 약수와 짝을 이루어 n에 근접한다.
따라서 제곱근 이상의 수부터 약수인지 판별하는 행위는 대칭이 자명한 상황이므로,
판별인 아닌 불필요한 절차이다.
*/

bool check(int n) {
	if (n <= 1) return 0;
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
