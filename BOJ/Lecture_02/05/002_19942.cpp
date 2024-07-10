#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

vector<vector<int>> value_table;
vector<int> best_combi, temp_combi;
int answer = INF;
int n, mp, mf, ms, mv;

void recur(int idx, int p, int f, int s, int v, int cost) {
    if (p >= mp && f >= mf && s >= ms && v >= mv) { //영양 조건 만족 시
        if (cost < answer) { //갱신되는 가격이 기존보다 싸다면 best_combi 변경
            answer = cost;
            best_combi = temp_combi;
        }
    }

    /*
    if(idx==n) 내부에 위 조건문을 중첩하지 않는 이유 :
    조건문을 이미 만족한다면 굳이 idx가 n이 될 때까지 억지로 cost를 늘려서 조합할 이유가 없음(best가 아니다)
    조건을 만족한 이후 idx가 증가하면 cost는 기존의 answer보다 무조건 커지기 때문에 문제 의도에 부합하지 않음
    cost가 최소가 되는 최고의 조합을 찾아야 하므로 idx에 상관없이 조건을 만족하면 answer값을 고정시켜 최소 cost를 유지한다

    하지만, idx가 n이 될 때까지 조건을 만족하지 못할 수도 있기 때문에 idx=n까지는 recur는 수행되어야 한다
    */

    //idx가 n이 되면 무조건 반환
    if (idx == n) {
        return;
    }

    //식재료를 선택하는 경우
    temp_combi.push_back(idx + 1); //인덱스 출력을 위한 + 1
    recur(idx + 1, p + value_table[idx][0], f + value_table[idx][1], s + value_table[idx][2], v + value_table[idx][3], cost + value_table[idx][4]);
    temp_combi.pop_back();

    //식재료를 선택하지 않는 경우
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
        for (int i : best_combi) {
            cout << i << ' ';
        }
    }
    
    return 0;
}
