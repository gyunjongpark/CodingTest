#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;

ll a, b;

/*
1부터 N까지의 2의 거듭 제곱 수의 합 구하기
수학적 공식이므로 암기할 것!
*/

ll solve(ll N) { 
	ll ret = N;

	for (ll i = 2; i <= N; i *= 2) {
		ret += (N / i) * (i / 2);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	cout << solve(b) - solve(a - 1);
	
	return 0;
}
