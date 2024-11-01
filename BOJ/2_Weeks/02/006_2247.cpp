#include<iostream>
using namespace std;
typedef long long ll;

ll n, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	//n은 2억 -> 시간 제한은 2초
	for (ll i = 2; i <= n; i++) { //약수 1 제외
		ll cnt = n / i; //본인 포함 i로 나눠지는 수들의 갯수 cnt

		//본인을 제외한 cnt에 자신의 가중치를 곱한 값을 순차적으로 더해 CSOD를 완성한다
		answer += (cnt - 1) * i;

		answer %= 1000000; //모듈러 연산
	}

	cout << answer;

	return 0;
}
