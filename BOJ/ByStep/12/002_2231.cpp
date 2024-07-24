#include<iostream>
using namespace std;

int n, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n; // 256을 예로 들면

    for (int i = 1; i < n; i++) {
        int sum = 0;
        int num = i; // i는 1부터 시작해서 245가 되었을 때

        while (num > 0) {
            sum += num % 10; //5 + 4 + 2
            num /= 10;
        }

        if (sum + i == n) { // 조건을 만족한다
            ret = i;
            break;
        }
    }
    cout << ret;

    return 0;
}
