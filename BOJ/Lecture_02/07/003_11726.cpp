#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    dp.resize(n + 1, 0);

    dp[0] = 1;
    dp[1] = 2;

    for (int idx = 2; idx < n; idx++) {
        dp[idx] = dp[idx - 1] + dp[idx - 2];
        dp[idx] %= 10007;
    }
    cout << dp[n - 1];

    return 0;
}
