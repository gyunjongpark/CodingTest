#include<iostream>
#include<cmath> //sqrt
using namespace std;
typedef long long ll;

ll gcd, lcm, ret_a, ret_b;

ll getGCD(ll a, ll b) {
	if (a == 0) return b;

	return getGCD(b % a, a);
}

void solve() {
	ll div = lcm / gcd; //서로소 ret_a, ret_b의 곱
	
	//sqrt까지만 조사하기 때문에 반복문을 돌수록 a, b의 차이가 줄어든다
	//a와 b는 서로소일 수도 있고 아닐 수도 있다. 단지 a * b = div이다. a = 1부터 완전 탐색
	for (ll i = 1; i <= (int)sqrt(div); i++) {
		if (div % i == 0) {
			ll a = i, b = div / i; //init

			//반복문을 거칠수록 가장 차이가 적은 서로소 관계의 두 수 ret_a, ret_b가 결정된다
			if (getGCD(a, b) == 1) {
				ret_a = a;
				ret_b = b;
			}
		}
	}
	//결정된 두 수에 최대 공약수를 곱해 최종적으로 조건에 만족하는 자연수를 구한다
	cout << ret_a * gcd << ' ' << ret_b * gcd;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> gcd >> lcm;
	solve();

	return 0;
}
