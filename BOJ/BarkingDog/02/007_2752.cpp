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

    for (int i = 0; i < 3; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}
