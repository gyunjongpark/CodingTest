#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> table;
vector<int> dp;
int n, t, p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    dp.resize(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        table.push_back({ t,p });
    }

    for (int idx = n - 1; idx >= 0; idx--) {
        dp[idx] = max(dp[idx], dp[idx + 1]);

        if (idx + table[idx].first <= n) {
            dp[idx] = max(dp[idx + table[idx].first] + table[idx].second, dp[idx + 1]);
        }
    }
    cout << dp[0];

    return 0;
}
