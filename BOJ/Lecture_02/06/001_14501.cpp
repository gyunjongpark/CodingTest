#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>> table;
vector<int> dp;
int n, t, p;
int answer = -INF;

int recur(int t) {
    if (t > n) return -INF;
    if (t == n) return 0;

    if (dp[t] != -1) return dp[t];

    //t > n일 때 recur는 -INF를 반환하므로 max로 선택되지 않는다
    //즉, t > n인 dp[t] 배열은 만들어지지 않는다
    dp[t] = max(recur(t + 1), recur(t + table[t].first) + table[t].second);

    return dp[t];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    //t > n일 때 recur는 -INF를 반환하므로 t > n인 dp[t] 배열은 만들어지지 않는다
    dp.resize(n + 1, -1);

    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        table.push_back({ t,p });
    }
    
    cout << recur(0);

    return 0;
}
