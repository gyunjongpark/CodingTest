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

    for (int idx = 0; idx < n; idx++) {
        dp[idx + 1] = max(dp[idx + 1], dp[idx]);

        if (idx + table[idx].first <= n) {
            dp[idx + table[idx].first] = max(dp[idx + table[idx].first], dp[idx] + table[idx].second);
        }
    }
    cout << dp[n];

    return 0;
}
