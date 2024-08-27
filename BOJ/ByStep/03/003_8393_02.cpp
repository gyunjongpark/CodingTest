#include<iostream>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cout << n * (n + 1) / 2; //수학적 접근 활용

    return 0;
}
