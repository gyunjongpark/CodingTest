#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> table;
vector<vector<int>> dp;
int n, k, m, v;

int recur(int idx, int weight) {
    if (idx > n || weight > k) return -1e9;
    if (idx == n) return 0;

    if (dp[idx][weight]!=-1) return dp[idx][weight];

    dp[idx][weight] = max(recur(idx + 1, weight), recur(idx + 1, weight + table[idx].first) + table[idx].second);

    return dp[idx][weight];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    dp.resize(n + 1, vector<int>(k + 1, -1)); //dp 입력은 push_back이 아니기 때문에 배열 초기화 필요

    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        table.push_back({ m,v });
    }

    cout << recur(0, 0);

    return 0;
}
