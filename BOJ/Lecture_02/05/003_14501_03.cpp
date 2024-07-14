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

    //idx = n - 1이고 idx + table[idx].first > n이라면 dp[idx] = dp[idx + 1]이므로 dp[n]이 필요하다
    //무급일 수도 있으므로 -1로 초기화
    dp.resize(n + 1, -1);
    dp[n] = 0; 

    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        table.push_back({ t,p });
    }
  
    for (int idx = n - 1; idx >= 0; idx--) {
        if (idx + table[idx].first > n) dp[idx] = dp[idx + 1];
        else {
            dp[idx] = max(dp[idx + table[idx].first] + table[idx].second, dp[idx + 1]);
        }
    }
    cout << dp[0];

    return 0;
}
