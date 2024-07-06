#include<iostream>
#include<cmath> //sqrt
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int x = n; //소인수 분해를 위한 변수 x
	for (int i = 2; i <= (int)sqrt(n); i++) {
		while (x % i == 0) { //while문의 조건 덕분에 소수가 되는 i만으로 반복문이 수행된다
			cout << i << '\n';
			x /= i;
		}
	}
	
	//sqrt(n)보다 크고 유일하면서 마지막인 소인수가 있다면 출력
	if (x != 1) cout << x << '\n';

	return 0;
}

/*
n=p*q를 만족하면서 p>sqrt(n) && q>sqrt(n)인 소수쌍 (p,q)는 존재하지 않는다(n을 넘어버리므로)
다시 말해 p>sqrt(n)라면 반드시 q<sqrt(n)이다

제곱근보다 큰 소인수가 p,q 두 개 이상이라면 p*q*r*s...>n 이므로 모순이다

따라서, 제곱근보다 큰 소인수는 많아봐야 최대 한 개이다.
*/
