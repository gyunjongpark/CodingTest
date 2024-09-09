#include<iostream>
#include<climits> //INT_MAX, INT_MIN
using namespace std;

int n, a[12], p, minu, mult;
int min_ret = INT_MAX;
int max_ret = INT_MIN;

void go(int here, int val, int p, int minu, int mult) {
    if (here == n - 1) {
        min_ret = min(min_ret, val);
        max_ret = max(max_ret, val);

        return;
    }

    if (p) go(here + 1, val + a[here + 1], p - 1, minu, mult);
    if (minu) go(here + 1, val - a[here + 1], p, minu - 1, mult);
    if (mult) go(here + 1, val * a[here + 1], p, minu, mult - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> p >> minu >> mult;

    go(0, a[0], p, minu, mult);

    cout << min_ret << ' ' << max_ret;

    return 0;
}
