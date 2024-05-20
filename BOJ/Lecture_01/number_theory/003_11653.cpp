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
	n=p*q에서 p>sqrt(n) && q>sqrt(n)인 합성수는 존재하지 않음
 	p>sqrt(n)라면 반드시 q<sqrt(n)이어야 함
  	따라서, 제곱근보다 큰 소인수는 많아야 한 개이다.
	*/
	
	for (int i = 2; i <= (int)sqrt(n); i++) {
		while (x % i == 0) {
			cout << i << '\n';
			x /= i;
		}
	}
	if (x != 1) cout << x << '\n'; //가장 큰 소인수 출력

	return 0;
}
