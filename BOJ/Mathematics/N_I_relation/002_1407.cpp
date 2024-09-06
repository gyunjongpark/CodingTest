#include<iostream>
using namespace std;
typedef long long ll;

ll a, b;

//1부터 N까지 2의 최대 승수를 각각 구해서 더함
ll solve(ll N) {
	ll ret = N; //각각의 수는 기본적으로 1(2^0)을 최소 승수로 가지므로 최소 결과값은 N이다

	for (ll i = 2; i <= N; i *= 2) {
		ret += (N / i) * (i / 2); //N!에서 2가 몇 번 포함되어 있는가? x 현재 승수에서 증가한만큼의 가중치 -> 최대 승수를 갱신한다
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
