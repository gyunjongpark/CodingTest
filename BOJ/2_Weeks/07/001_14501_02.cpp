#include<iostream>
using namespace std;

int n, t[16], p[16], dp[16];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i + 1] = max(dp[i + 1], dp[i]);

		if (i + t[i] <= n) {
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
		}
	}

	cout << dp[n];

	return 0;
}
