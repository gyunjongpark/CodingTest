#include <iostream>
using namespace std;

int n, dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1; //3번 방법(1, 2번 방법이 안될 때 사용)

        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1); //2번 방법
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1); //1번 방법
    }

    cout << dp[n];

    return 0;
}
