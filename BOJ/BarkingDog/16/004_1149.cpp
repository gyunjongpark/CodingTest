#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, r, g, b;
int answer = INT_MAX;
vector<vector<int>> house, dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    dp.resize(n, vector<int>(3, 0)); //n행 3열, 0으로 초기화

    //n - 1번째 집의 dp를 구한다
    for (int i = 0; i < n; i++) {
        cin >> r >> g >> b;
        house.push_back({ r,g,b }); //house 역시 n행 3열이라는 정보가 제공된다
    }

    //dp 첫 번째 행을 집의 첫번째 행으로 초기화
    for (int i = 0; i < 3; i++) {
        dp[0][i] = house[0][i];
    }

    //이후의 행은 현재 행의 집 + 이전 행 중 다른 색상의 집 중 최소 비용 선택
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
    }

    answer = min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);

    cout << answer;

    return 0;
}
