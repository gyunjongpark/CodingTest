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

    // dp[n] = max(dp[n + 1], dp[n])이므로 dp의 길이는 n + 1까지 필요하다
    // dp[n]를 정의하지 않고 처음부터 max로 값을 비교한다. 따라서 0으로 초기화
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
