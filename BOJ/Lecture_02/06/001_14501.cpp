#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>> table;
vector<int> dp;
int answer = -INF;
int n, d, p;

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

    dp.resize(n + 1, -1);

    for (int i = 0; i < n; i++) {
        cin >> d >> p;
        table.push_back({ d,p });
    }
    cout << recur(0);
    
    return 0;
}
