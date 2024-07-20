#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

vector<vector<int>> ingre;
vector<int> best_combi, temp_combi;
int p, f, s, v, cost;
int n, mp, mf, ms, mv;
int answer = INF;

// 같은 비용의 집합이 하나 이상이면 사전 순으로 가장 빠른 것을 출력한다
// 영양 기준을 만족한다면 굳이 idx는 n까지 가지 않아도 된다

void recur(int idx, int p, int f, int s, int v, int cost) {
    if (p >= mp && f >= mf && s >= ms && v >= mv) {

        // idx == n 조건문 밖에서 answer 도출
        if (cost < answer) {
            answer = cost; 
            best_combi = temp_combi;

            return; // 최초로 조건을 만족하는 조합이 가장 비용이 적게 드는 조합이며, 사전 순으로도 가장 빠르다
        }
    }

    if (idx == n) return; // idx가 n이 된다면 무조건 반환


    // 식재료를 선택하는 경우
    temp_combi.push_back(idx + 1); // idx 변화가 없는 시점에서 조합을 우선적으로 생성한 후 재귀 함수를 호출한다
    recur(idx + 1, p + ingre[idx][0], f + ingre[idx][1], s + ingre[idx][2], v + ingre[idx][3], cost + ingre[idx][4]);
    temp_combi.pop_back();

    // 식재료를 선택하지 않는 경우
    recur(idx + 1, p, f, s, v, cost);

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> mp >> mf >> ms >> mv;

    for (int i = 0; i < n; i++) {
        cin >> p >> f >> s >> v >> cost;
        ingre.push_back({ p,f,s,v,cost });
    }

    recur(0, 0, 0, 0, 0, 0); // idx, p, f, s, v, cost

    if (answer == INF) {
        cout << -1;
    }
    else {
        cout << answer << '\n';
        for (int i : best_combi) {
            cout << i << ' ';
        }
    }

    return 0;
}
