#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> backpack;
vector<vector<int>> dp;
int n, k, w, v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    dp.resize(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        backpack.push_back({ w,v });
    }

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int weight = k - 1; weight >= 0; weight--) {
            if (weight + backpack[idx].first > k) dp[idx][weight] = dp[idx + 1][weight];
            else {
                dp[idx][weight] = max(dp[idx + 1][weight], dp[idx + 1][weight + backpack[idx].first] + backpack[idx].second);
            }
        }
    }
    cout << dp[0][0];

    return 0;
}
