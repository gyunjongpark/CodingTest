/*

O(2^n)의 시간복잡도. n<=100이므로 재귀적인 방법은 시간 초과 발생

#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> table;
int n, k, m, v;
int answer = -1;

void recur(int idx, int m, int v) {
    if (m > k) return;
    if (idx == n) {
        answer = max(answer, v);
        return;
    }

    recur(idx + 1, m, v);
    recur(idx + 1, m + table[idx].first, v + table[idx].second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        table.push_back({ m,v });
    }

    recur(0, 0, 0);

    cout << answer;

    return 0;
}

*/
