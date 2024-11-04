#include <iostream>
using namespace std;

int n, k;

int factorial(int n, int k) {
    int ret1 = 1;

    for (int i = 0; i < k; i++) { //k번 반복
        ret1 *= n;
        n--;
    }

    int ret2 = 1;
    for (int i = 0; i < k; i++) { //k번 반복
        ret2 *= (i + 1);
    }

    return ret1 / ret2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    cout << factorial(n, k);
    

    return 0;
}
