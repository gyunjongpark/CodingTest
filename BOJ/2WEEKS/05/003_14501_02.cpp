#include<iostream>
#include<vector>
using namespace std;

int n, t, p, table[15][2]; // 배열을 미리 생성
int answer = -1;

void recur(int t, int p) {
    if (t > n) return;
    if (t == n) {
        answer = max(answer, p);
        return;
    }

    recur(t + 1, p);
    recur(t + table[t][0], p + table[t][1]);

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> table[i][0] >> table[i][1];
    }

    recur(0,0);

    cout << answer;

    return 0;
}
