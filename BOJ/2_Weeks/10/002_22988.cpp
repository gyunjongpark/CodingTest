#include<iostream>
#include<algorithm> //sort
using namespace std;
typedef long long ll;

ll n, x, a[100001], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    //two pointer
    int l = 0, r = n - 1;
    int remain = 0;

    while (r >= 0 && a[r] >= x) {
        r--;
        ret++;
    }
    while (l <= r) {
        if (l < r && a[l] + a[r] >= (x + 1) / 2) {
            ret++;
            l++;
            r--;
        }
        else {
            l++;
            remain++;
        }
    }

    cout << ret + remain / 3;

    return 0;
}