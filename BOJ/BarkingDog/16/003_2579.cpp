#include<iostream>
using namespace std;

int t, n, cnt, dp[301], a[301];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    //init
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    dp[3] = max(a[1], a[2]) + a[3];

    for (int i = 4; i <= n; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3] + a[i - 1]) + a[i];
    }

    cout << dp[n];

    return 0;
}
