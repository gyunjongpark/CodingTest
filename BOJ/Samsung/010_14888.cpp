#include<iostream>
#include<climits> //INT_MAX, INT_MIN
using namespace std;

int n, a[12], plu, minu, mult, divi;
int min_ret = INT_MAX;
int max_ret = INT_MIN;

void go(int here, int val, int p, int minu, int mult, int divi) {
    if (here == n - 1) {
        min_ret = min(min_ret, val);
        max_ret = max(max_ret, val);

        return;
    }

    if (p) go(here + 1, val + a[here + 1], p - 1, minu, mult, divi);
    if (minu) go(here + 1, val - a[here + 1], p, minu - 1, mult, divi);
    if (mult) go(here + 1, val * a[here + 1], p, minu, mult - 1, divi);
    if (divi) go(here + 1, val / a[here + 1], p, minu, mult, divi - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> plu >> minu >> mult >> divi;

    go(0, a[0], plu, minu, mult, divi);

    cout << max_ret << '\n' << min_ret;

    return 0;
}
