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

    //idx = n - 1이고 idx + table[idx].first > n이라면 dp[idx] = dp[idx + 1]. 즉, dp[n]이 필요하다
    //무급(열정페이!)일 수도 있으므로 -1로 초기화
    dp.resize(n + 1, -1);
    
    //탑다운에서 idx == n일 때 return 0 반환 -> dp[n] = 0. 다시 말해, 변형을 주지 말아야 한다
    dp[n] = 0; 

    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        table.push_back({ t,p });
    }
    
    //idx = n - 1이고 idx + table[idx].first > n이라면 dp[idx] = dp[idx + 1]. 즉, dp[n]이 필요하다
    for (int idx = n - 1; idx >= 0; idx--) {
        if (idx + table[idx].first > n) dp[idx] = dp[idx + 1];
        else {
            dp[idx] = max(dp[idx + table[idx].first] + table[idx].second, dp[idx + 1]);
        }
    }
    cout << dp[0];

    return 0;
}
