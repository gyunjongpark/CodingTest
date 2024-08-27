#include<iostream>
using namespace std;
typedef long long ll;

ll a, b;

//1부터 N까지 2의 최대 승수를 각각 구하고 더함
ll solve(ll N) {
	ll ret = N; //2^0으로 나누어 떨어지는 수(모든 수)를 초기값으로 저장

	for (ll i = 2; i <= N; i *= 2) {
		ret += (N / i) * (i / 2); //2로 나누어 떨어지는 동안 가중치를 곱해서 결과값에 저장
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
