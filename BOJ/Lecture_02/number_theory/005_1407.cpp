#include<iostream>
using namespace std;
typedef long long ll;

ll a, b;

//1부터 N까지 각각의 수가 나눠질 수 있는 2의 최대 승수를 구해서 더함
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
