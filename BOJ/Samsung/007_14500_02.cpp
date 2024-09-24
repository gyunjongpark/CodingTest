#include<iostream>
#include<vector>
using namespace std;

vector<vector<pair<int, int>>> tet = {
    {{0,1},{0,2},{0,3}}, {{1,0},{2,0},{3,0}}, //ㅣ 회전
    {{0,1},{1,0},{1,1}}, //ㅁ
    {{1,0},{2,0},{2,1}}, {{1,0},{0,1},{0,2}},{{0,1},{1,1},{2,1}},{{0,1},{0,2},{-1,2}}, //ㄴ 회전
    {{0,1},{1,0},{2,0}}, {{1,0},{1,1},{1,2}},{{0,1},{-1,1},{-2,1}},{{0,1},{0,2},{1,2}}, //ㄴ 대칭 후 회전
    {{1,0},{1,1},{2,1}},{{0,1},{-1,1},{-1,2}}, //ㄹ 회전
    {{1,0},{0,1},{-1,1}},{{0,1},{1,1},{1,2}}, //ㄹ 대칭 후 회전
    {{0,1},{0,2},{1,1}}, {{-1,1},{0,1},{1,1}},{{0,1},{0,2},{-1,1}},{{1,0},{2,0},{1,1}} //ㅏ 회전
};

int n, m, a[501][501], ret, sum;

int get_score(int i, int j, int k) {
    int sum = a[i][j]; //기준점 먼저 더하기

    for (int t = 0; t < 3; t++) { //tet 하나는 3개의 좌표를 가지고 있다
        int y = i + tet[k][t].first;
        int x = j + tet[k][t].second;

        if (y < 0 || y >= n || x < 0 || x >= m) continue;

        sum += a[y][x];
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < tet.size(); k++) {
                sum = get_score(i, j, k);
                ret = max(ret, sum);
            }
        }
    }

    cout << ret;

    return 0;
}
