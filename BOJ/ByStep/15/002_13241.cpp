#include<iostream>
using namespace std;
typedef long long ll;

ll a, b; //큰 수 입력에 대하여 변수를 64비트 정수로 선언하시오. C/C++에서는 long long int를 사용하고, Java에서는 long을 사용하시오.

ll getGCD(ll a, ll b) {
	if (a == 0) return b;
	getGCD(b % a, a);
}

ll getLCM(ll a, ll b) {
	return a * b / getGCD(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	cout << getLCM(a, b) << '\n';

	return 0;
}
