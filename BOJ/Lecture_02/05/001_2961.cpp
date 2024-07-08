#include<iostream>
#include<vector>
#include<cmath> //abs
#define INF 1e6
using namespace std;

vector<pair<int, int>> ingre;
int answer = INF;
int n, s, b;

void recur(int idx, int sour, int bitter, int used) {
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
        cin >> s >> b; //sour, bitter
        ingre.push_back({ s,b });
    }
    recur(0, 1, 0, 0); //쓴 맛은 곱이기 때문에 초기값 1

    cout << answer;

    return 0;
}
