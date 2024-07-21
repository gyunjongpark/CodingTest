#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> table;
int n, t, p, dp[15 + 1]; // 배열을 이용한 풀이

int recur(int t) {
    if (t > n) return -1e9;
    if (t == n) return 0;

    if (dp[t] != -1) return dp[t]; // 갱신되었다면 그대로 쓰기

    dp[t] = max(recur(t + 1), recur(t + table[t].first) + table[t].second);

    return dp[t];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    // dp 입력은 push_back이 아니기 때문에 초기화 필요
    fill(dp, dp + n + 1, -1);

    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        table.push_back({ t,p });
    }

    cout << recur(0);

    return 0;
}
