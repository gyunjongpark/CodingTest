#include<iostream>
#include<cmath>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	int x = n;

	//소인수분해
	
	/*
	sqrt(n)까지만 조사해도 되는 이유
	제곱근 이상의 수는 반드시 제곱근 이하의 수와 짝을 이루기 때문입니다.
	*/
	for (int i = 2; i <= (int)sqrt(n); i++) {
		while (x % i == 0) {
			cout << i << '\n';
			x /= i;
		}
	}
	if (x != 1) cout << x << '\n';

	return 0;
}
