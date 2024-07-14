#include<iostream>
#include<vector>
#include<cmath> //abs
#define INF 1e9
using namespace std;

vector<pair<int, int>> ingre;
int n, s, b;
int answer = INF;

void recur(int idx, int sour, int bitter, int used) {
    //전체 경우의 수 중에서 최소 판단. idx == n 조건문 내에서 answer 도출
    if (idx == n) {
        if (used > 0) {
            answer = min(answer, abs(sour - bitter));
        }

        return;
    }

    recur(idx + 1, sour * ingre[idx].first, bitter + ingre[idx].second, used + 1);
    recur(idx + 1, sour, bitter, used);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s >> b;
        ingre.push_back({ s,b });
    }

    recur(0, 1, 0, 0);

    cout << answer;

    return 0;
}
