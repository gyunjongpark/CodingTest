#include <iostream>
#include <vector>
using namespace std;

int n, table[20][2], dp[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> table[i][0] >> table[i][1];
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);

        if (i + table[i][0] <= n + 1) {
            dp[i + table[i][0] - 1] = max(dp[i + table[i][0] - 1], dp[i - 1] + table[i][1]);
        }
        
    }
    cout << dp[n];

    return 0;
}
