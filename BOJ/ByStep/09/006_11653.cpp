#include<iostream>
#include<cmath> //sqrt
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	/*
  	n=p*q를 만족하면서 p>sqrt(n) && q>sqrt(n)인 소수쌍 (p,q)는 존재하지 않음
  	제곱근보다 큰 소인수가 p,q 두 개 이상이라면 p*q*r*s...>n 이므로 모순이기 때문에
   	제곱근보다 큰 소인수는 많아봐야 최대 한 개이다.
	*/
  
	int x = n; //변수 x를 이용한 n값 고정
	for (int i = 2; i <= (int)sqrt(n); i++) {
		while (x % i == 0) {
			cout << i << '\n';
			x /= i;
		}
	}
	if (x != 1) cout << x << '\n'; //가장 큰 소인수 출력

	return 0;
}
