#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>> table;
vector<int> dp;
int n, t, p;

int recur(int t) {
    if (t > n) return -INF;
    if (t == n) return 0;

    if (dp[t]!=-1) return dp[t]; //이미 정의되었다면 그대로 반환(메모이제이션)

    //t >= n일 때 recur(t)는 dp 배열을 만들지 않고 값을 반환한다
    dp[t] = max(recur(t + 1), recur(t + table[t].first) + table[t].second);

    return dp[t];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    //t >= n일 때 recur(t)는 dp 배열을 만들지 않고 값을 반환한다, 즉 dp[0] ~ dp[n - 1]까지
    //다른 문제에서는 무급(열정페이!)일 수도 있으므로 -1로 초기화
    dp.resize(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        table.push_back({ t,p });
    }
    cout << recur(0); //탑다운 dp

    return 0;
}
