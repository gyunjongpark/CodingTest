#include<iostream>
#include<algorithm> //sort
using namespace std;

int a[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    sort(a, a + 3);

    if (a[0] + a[1] > a[2]) cout << a[0] + a[1] + a[2];
    else cout << (a[0] + a[1]) * 2 - 1;

    return 0;
}
