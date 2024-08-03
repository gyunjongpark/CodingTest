#include <iostream>
using namespace std;

int n, i;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    if (n == 1) cout << 1;
    else {
        for (int sum = 2; sum <= n; i++) {
            sum += 6 * i;
        }
        
        cout << i;
    }

    return 0;
}
