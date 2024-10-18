#include<iostream>
using namespace std;

int dp[11], t, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    dp[1] = 1; dp[2] = 2; dp[3] = 4; //init

    cin >> t;

    for (int i = 4; i < 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
