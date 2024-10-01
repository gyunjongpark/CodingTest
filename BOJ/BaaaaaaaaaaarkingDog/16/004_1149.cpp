#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

vector<vector<int>> house, dp;
int n, r, g, b;
int answer = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    dp.resize(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++) {
        cin >> r >> g >> b;
        house.push_back({ r,g,b });
    }

    //첫 번째 집을 dp[0]의 원소로 초기화
    for (int i = 0; i < 3; i++) {
        dp[0][i] = house[0][i];
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
    }

    answer = min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);

    cout << answer;

    return 0;
}
