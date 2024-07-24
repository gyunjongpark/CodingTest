#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> table;
vector<vector<int>> dp;
int n, k, w, v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    dp.resize(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        table.push_back({ w,v });
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = k - 1; j >= 0; j--) {
            dp[i][j] = max(dp[i][j], dp[i + 1][j]);
            if (j + table[i].first <= k) {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + table[i].first] + table[i].second);
            }
        }
    }
    cout << dp[0][0];

    return 0;
}
