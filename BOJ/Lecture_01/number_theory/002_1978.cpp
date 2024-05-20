#include<iostream>
#include<cmath>
using namespace std;

int a, n, ret;

bool check(int n) {
	if (n == 1) return 0;
	
	/*
	sqrt(n)까지만 조사해도 되는 이유는
	제곱근 이상의 수는 반드시 제곱근 이하의 수와 짝을 이루기 때문입니다.
	*/
	
	for (int i = 2; i <= (int)sqrt(n); i++) { //sqrt
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
