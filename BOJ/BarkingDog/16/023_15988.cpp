#include<iostream>
using namespace std;
typedef long long ll;

int t, n;
ll dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    dp[1] = 1; dp[2] = 2; dp[3] = 4; //init

    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 4; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
        }

        cout << dp[n] << '\n';
    }

    return 0;
}
