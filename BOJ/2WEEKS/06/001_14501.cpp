#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> table;
vector<int> dp;
int n, t, p;

int recur(int t) {
    if (t > n) return -1e9;
    if (t == n) return 0;

    if (dp[t]!=-1) return dp[t];

    dp[t] = max(recur(t + 1), recur(t + table[t].first) + table[t].second);

    return dp[t];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    dp.resize(n + 1, -1);

    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        table.push_back({ t,p });
    }

    cout << recur(0);

    return 0;
}
