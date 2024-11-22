#include<iostream>
#include<queue>
using namespace std;

struct scv_hp {
    int a, b, c;
};

int n, a[3], visited[61][61][61], ret;
int atk[6][3]{ //공격할 수 있는 경우의 수
    {9,3,1},
    {9,1,3},
    {3,1,9},
    {3,9,1},
    {1,3,9},
    {1,9,3},
};

void bfs(int a, int b, int c) {
    visited[a][b][c] = 1;

    queue<scv_hp> q;
    q.push({ a,b,c });

    while (!q.empty()) {
        scv_hp cur = q.front(); q.pop();

        if (visited[0][0][0]) { //탈출 조건
            ret = visited[0][0][0] - 1;
            break;
        };

        for (int i = 0; i < 6; i++) {
            int nxt_a = max(0, cur.a - atk[i][0]);
            int nxt_b = max(0, cur.b - atk[i][1]);
            int nxt_c = max(0, cur.c - atk[i][2]);

            if (!visited[nxt_a][nxt_b][nxt_c]) {
                visited[nxt_a][nxt_b][nxt_c] = visited[cur.a][cur.b][cur.c] + 1;
                q.push({ nxt_a,nxt_b,nxt_c });
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bfs(a[0], a[1], a[2]);

    cout << ret;

    return 0;
}
