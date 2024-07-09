#include<iostream>
#include<vector>
#define INF -987654321
using namespace std;

vector<pair<int, int>> table;
int n, t, p;

int recur(int day) {
    if (day > n) return INF;
    if (day == n) {
        return 0;
    }

    return max(recur(day + 1), recur(day + table[day].first) + table[day].second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        table.push_back({ t,p });
    }
    cout<<recur(0);

    return 0;
}
