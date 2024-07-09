#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>> table;
vector<int> dp;
int n, t, p, answer;

int recur(int day) {
    if (day > n) return -INF;
    if (day == n) return 0;

    if (dp[day] != -1) return dp[day];

    dp[day] = max(recur(day + table[day].first) + table[day].second, recur(day + 1));

    return dp[day];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    table.resize(n);
    dp.resize(n,-1);

    for (int i = 0; i < n; i++) {
        cin >> t >> p; //T, P
        table[i] = { t,p };
    }
    cout<<recur(0);

    return 0;
}
