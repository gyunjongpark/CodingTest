#include<iostream>
using namespace std;

int n, m, a[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxVal = -1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                int card = a[i] + a[j] + a[k];
                if (card <= m && maxVal < card) maxVal = card;
            }
        }
    }
    cout << maxVal;

    return 0;
}
