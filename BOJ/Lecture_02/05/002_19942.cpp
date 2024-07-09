#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

vector<vector<int>> value_table;
vector<int> effective_combination, sufficient_combination;
int answer = INF;
int n, mp, mf, ms, mv;

void recur(int idx,int p,int f,int s,int v,int cost) {
    if (p >= mp && f >= mf && s >= ms && v >= mv) {
        if (cost < answer) {
            answer = cost;
            effective_combination = sufficient_combination;
        }
    }

    //조건을 이미 만족하여 추가적으로 식재료를 선택하는 것이 불필요하다
    //굳이 idx가 n이 될 때까지 억지로 조합할 이유가 없음
    //idx에 상관없이 조건을 만족하기만 하면 바로 answer값을 변경한다
    //조건을 만족한 이후 idx가 증가할수록 cost는 기존의 answer보다 커지기 때문에 사실상 의미가 없다

    //idx가 n이 될 때까지 조건을 만족하지 못할 수도 있기 때문에 n까지는 무조건 호출
    //idx가 n이 되면 무조건 반환
    if (idx == n) {
        return;
    }

    //식재료를 선택하는 경우
    sufficient_combination.push_back(idx + 1);
    recur(idx + 1, p + value_table[idx][0], f + value_table[idx][1], s + value_table[idx][2], v + value_table[idx][3], cost + value_table[idx][4]);
    sufficient_combination.pop_back();

    //선택하지 않는 경우
    recur(idx + 1, p, f, s, v, cost);

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> mp >> mf >> ms >> mv;

    value_table.resize(n, vector<int>(5));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> value_table[i][j];
        }
    }

    recur(0, 0, 0, 0, 0, 0);

    if (answer == INF) {
        cout << -1;
    }
    else {
        cout << answer << '\n';
        for (int i : effective_combination) {
            cout << i << ' ';
        }
    }

    return 0;
}
