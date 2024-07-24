#include<iostream>
#include<vector>
using namespace std;

int n, k, w, v;
vector<pair<int, int>> backpack;
vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    dp.resize(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        backpack.push_back({ w,v });
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);

            if (j - backpack[i - 1].first >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - backpack[i - 1].first] + backpack[i - 1].second);
            }
        }
    }
    cout << dp[n][k];

    return 0;
}
