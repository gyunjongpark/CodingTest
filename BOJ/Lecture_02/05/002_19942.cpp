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
        if (cost < answer) { //cost가 기존의 answer보다 싸다면 best_combi 변경
            answer = cost;
            best_combi = temp_combi;
        }
    }

    /*
    if(idx==n) 내부로 위 조건문을 중첩하지 않는 이유 : 같은 비용의 집합이 하나 이상이면 사전 순으로 가장 빠른 것을 출력한다    
    즉, 영양 조건을 이미 만족한다면 굳이 idx가 n이 될 때까지 조합할 이유가 없다

    하지만, idx가 n이 될 때까지 조건을 만족하지 못할 수도 있기 때문에 idx=n까지는 recur는 수행되어야 한다
    */

    //idx가 n이 되면 반환
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
