#include<iostream>
using namespace std;
typedef unsigned long long ll;

ll n, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	for (ll i = 2; i <= n; i++) { //약수 1 제외
		ll cnt = n / i; //1 ~ n 중에서 현재 i가 곱해진 경우를 하나씩 계산

		//본인을 제외한 cnt에 자신의 가중치를 곱해서 CSOD(n)을 완성한다
		answer += (cnt - 1) * i;

		answer %= 1000000; //모듈러 연산
	}

	cout << answer;

	return 0;
}

//N_I_relation : [ for(int i=a -> n; i*=a) N/i ]를 기반으로 짧은 범위의 수를 직접 종이에 나열 후 규칙성을 도출하는 것이 가장 빠른 해법같다.
