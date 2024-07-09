#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> table;
int n, t, p, answer;

void recur(int day, int price) {
    if (day > n) return;
    if (day == n) {
        answer = max(answer, price);
        return;
    }

    recur(day + table[day].first, price + table[day].second);
    recur(day + 1, price);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    table.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        table[i] = { t,p };
    }

    recur(0, 0);

    cout << answer;

    return 0;
}
