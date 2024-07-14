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

    //인덱스가 n을 넘으면 dp[idx + 1]을 가져오므로 바텀업 dp는 n + 1까지 정의한다
    //무급(열정페이!)일 수도 있으므로 -1로 초기화
    dp.resize(n + 1, -1);
    
    dp[n] = 0; //탑다운에서 idx == n일 때 return 0 반환 -> dp[n] = 0

    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        table.push_back({ t,p });
    }
    
    //인덱스가 n을 넘으면 dp[idx + 1]을 가져오므로 바텀업 dp는 n + 1까지 정의한다
    for (int idx = n - 1; idx >= 0; idx--) {
        if (idx + table[idx].first > n) dp[idx] = dp[idx + 1];
        else {
            dp[idx] = max(dp[idx + table[idx].first] + table[idx].second, dp[idx + 1]);
        }
    }
    cout << dp[0];

    return 0;
}
