#include<iostream>
#include<vector>
using namespace std;

int n, k, backpack[104][104], dp[104][100004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> backpack[i][0] >> backpack[i][1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j - backpack[i][0] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - backpack[i][0]] + backpack[i][1]);
            }
        }
    }
    cout << dp[n][k];

    return 0;
}
