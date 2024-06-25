#include<iostream>
using namespace std;

int n, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n; //256

    for (int i = 1; i < n; i++) {
        int sum = 0;
        int num = i;

        while (num > 0) {
            sum += num % 10; //2+4+5
            num /= 10;
        }

        if (sum + i == n) { //i=245
            ret = i;
            break;
        }
    }
    cout << ret;

    return 0;
}
