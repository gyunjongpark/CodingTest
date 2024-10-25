#include<iostream>
using namespace std;

int n, temp, dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	fill(dp, dp + 100001, -1001);

	for (int i = 1; i <= n; i++) {
		cin >> temp;
    
		dp[i] = max(dp[i - 1] + temp, temp);
	}

	int maxVal = -1001;

	for (int i = 1; i <= n; i++) {
		maxVal = max(maxVal, dp[i]);
	}

	cout << maxVal;

	return 0;
}
