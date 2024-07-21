#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> table;
int n, t, p;
int answer = -1;

void recur(int t, int p) {
    if (t > n) return;
    if (t == n) {
        answer = max(answer, p);
        return;
    }

    recur(t + 1, p);
    recur(t + table[t].first, p + table[t].second);

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        table.push_back({ t,p });
    }

    recur(0,0);

    cout << answer;

    return 0;
}
