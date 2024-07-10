#include<iostream>
#include<vector>
#include<cmath> //abs
#define INF 1e9
using namespace std;

vector<pair<int, int>> table;
int n, s, b;
int answer = INF;

void recur(int idx, int sour, int bitter, int used) {
    if (idx == n) {
        if (used > 0) {
            answer = min(answer, abs(sour - bitter));
        }
        return;
    }

    recur(idx + 1, sour * table[idx].first, bitter + table[idx].second, used + 1);
    recur(idx + 1, sour, bitter, used);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    table.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> s >> b;
        table[i] = { s,b };
    }
    recur(0, 1, 0, 0);

    cout << answer;

    return 0;
}
