#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>> table;
int n, t, p;
int answer = -INF;

void recur(int t, int p) {
    if (t > n) return; //table 범위를 벗어나면 return

    //돈을 최대로 받기 위해서 마지막 날까지의 경우의 수 조사
    //idx == n 조건문 내에서 answer 도출
    if (t == n) {
        answer = max(answer, p);
        return;
    }

    recur(t + table[t].first, p + table[t].second);
    recur(t + 1, p);

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
    
    recur(0, 0);

    cout << answer;

    return 0;
}
