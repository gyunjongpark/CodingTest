#include<iostream>
using namespace std;

int t, n, dp[41];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

  //init
	dp[0] = 0;
	dp[1] = 1;

	//일반적인 피보나치 수열에 따른 dp 완성
	for (int i = 2; i <= 40; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cin >> t;

	while (t--) {
		cin >> n;

		if (n == 0) cout << 1 << ' ' << 0 << '\n';
		else if (n == 1) cout << 0 << ' ' << 1 << '\n';
		else cout << dp[n - 1] << ' ' << dp[n] << '\n'; //도식화 후 규칙성 찾고 완성된 dp와 연관 짓는다
	}

	return 0;
}