#include<iostream>
using namespace std;

int t, n, cnt;

void recur(int num) {
    if (num > n) return;

    if (num == n) {
        cnt++;
        return;
    }

    recur(num + 1);
    recur(num + 2);
    recur(num + 3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        cnt = 0;
        cin >> n;

        recur(1);
        recur(2);
        recur(3);

        cout << cnt << '\n';
    }

    return 0;
}
