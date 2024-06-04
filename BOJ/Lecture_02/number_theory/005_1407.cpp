#include<iostream>
using namespace std;
typedef long long ll;

ll a, b;

ll solve(ll N) { //1부터 N까지 2의 최대 승수를 각각 구하고 더함
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
