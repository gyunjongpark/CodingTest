#include <iostream>
using namespace std;

int n, dp[1000001], pre[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    //init
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1; //3번 방법(1, 2번 방법이 안될 때 사용)
        pre[i] = i - 1;

        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) { //2번 방법
            dp[i] = dp[i / 2] + 1;
            pre[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) { //1번 방법
            dp[i] = dp[i / 3] + 1;
            pre[i] = i / 3;
        }
    }

    cout << dp[n] << '\n';

    int cur = n;

    while (true) {
        cout << cur << ' ';

        if (cur == 1) break;

        cur = pre[cur];
    }

    return 0;
}