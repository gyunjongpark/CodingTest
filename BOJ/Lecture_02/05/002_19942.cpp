#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10004
using namespace std;

vector<vector<int>> ingre;
vector<int> selectedIngredients, bestCombination;
int answer = MAX;
int n, mp, mf, ms, mv;


void recur(int idx, int a, int b, int c, int d, int cost) {
    if (a >= mp && b >= mf && c >= ms && d >= mv) {
        if (cost < answer) {
            answer = cost;
            bestCombination = selectedIngredients; //size가 최소인 조합을 저장한다
        }
    }
    if (idx == n) { // 모든 재료 검사 후 종료
        return;
    }

    // 현재 재료를 선택하는 경우
    selectedIngredients.push_back(idx + 1); // 인덱스 1부터 시작
    recur(idx + 1, a + ingre[idx][0], b + ingre[idx][1], c + ingre[idx][2], d + ingre[idx][3], cost + ingre[idx][4]);
    selectedIngredients.pop_back(); // 원상 복구

    // 현재 재료를 선택하지 않는 경우
    recur(idx + 1, a, b, c, d, cost);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> mp >> mf >> ms >> mv;

    ingre.resize(n, vector<int>(5));

    for (int i = 0; i < n; i++) {
        cin >> ingre[i][0] >> ingre[i][1] >> ingre[i][2] >> ingre[i][3] >> ingre[i][4];
    }

    recur(0, 0, 0, 0, 0, 0);

    if (answer == MAX) {
        cout << -1;
    }
    else {
        cout << answer << '\n';      
        for (int i : bestCombination) {
            cout << i << ' ';
        }
    }

    return 0;
}
