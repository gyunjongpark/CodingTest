#include<iostream>
#include<climits> //INT_MIN
using namespace std;

int n, l, a[101][101], b[101][101], ret;

void go(int a[101][101]) {
    for (int i = 0; i < n; i++) {
        int cnt = 1, j = 0;

        for (j = 0; j < n - 1; j++) {
            if (a[i][j] == a[i][j + 1]) cnt++;
            else if (a[i][j] == a[i][j + 1] - 1 && cnt >= l) cnt = 1;
            else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1;
            else break;
        }

        if (j == n - 1 && cnt >= 0) ret++;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];

            b[j][i] = a[i][j];
        }
    }

    go(a);
    go(b);

    cout << ret;

    return 0;
}
