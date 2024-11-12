#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, m, a[500001], b[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    //투포인터를 통한 이분탐색
    for (int i = 0; i < m; i++) {
        int l = 0, r = n - 1;
        bool flag = false;

        while (l <= r) {
            int mid = (l + r + 1) / 2;

            if (a[mid] == b[i]) {
                flag = true;
                break;
            }
            else if (a[mid] > b[i]) {
                r = mid - 1;
            }
            else if (a[mid] < b[i]) {
                l = mid + 1;
            }
        }

        if (flag) cout << 1 << ' ';
        else cout << 0 << ' ';
    }

    return 0;
}
