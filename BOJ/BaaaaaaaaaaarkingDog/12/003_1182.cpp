#include<iostream>
using namespace std;

int n, s, ret, a[21];

void recur(int cur, int sum) {
    if (cur == n) {
        if (sum == s) ret++;
        return;
    }

    recur(cur + 1, sum);
    recur(cur + 1, sum + a[cur]);

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    recur(0, 0);

    if (s == 0) ret--;

    cout << ret;

    return 0;
}
