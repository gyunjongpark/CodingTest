/* 시간 초과 코드
#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>> backpack;
int answer = -INF;
int n, w, k, v;

void recur(int idx, int weight, int value) {
    if (weight > k) return;
    if (idx == n) {
        answer = max(answer, value);
        return;
    }

    recur(idx + 1, weight + backpack[idx].first, value + backpack[idx].second);
    recur(idx + 1, weight, value);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        backpack.push_back({ w,v });
    }
    recur(0, 0, 0);

    cout << answer;

    return 0;
}
*/
