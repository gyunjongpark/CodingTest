#include<iostream>
#include<vector>
#include<cmath> //abs
using namespace std;

vector<pair<int, int>> ingre;
int answer = 1e6, n;

void recur(int idx, int s, int b, int use) {
    if (idx == n) {
        if (use > 0) {
            answer = min(answer, abs(s - b));
        }
        return;
    }

    recur(idx + 1, s * ingre[idx].first, b + ingre[idx].second, use + 1);
    recur(idx + 1, s, b, use);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    int s, b;
    for (int i = 0; i < n; i++) {
        cin >> s >> b;
        ingre.push_back({ s,b });
    }
    recur(0, 1, 0, 0);

    cout << answer;

    return 0;
}
