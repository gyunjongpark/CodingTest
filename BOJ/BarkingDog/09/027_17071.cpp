#include<iostream>
#include<queue>
using namespace std;

int n, k;
int ret = -1;
int mov = 1; //동생이 움직일 수 있는 거리
bool visited[2][500001];

void bfs(int n) {
    visited[0][n] = true;

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        k += mov;

        if (k > 500000) {
            ret = -1;
            break;
        }
      
        if (visited[mov % 2][k]) {
            ret = mov;
            break;
        }

        int q_size = q.size();
        bool flag = false;

        while (q_size--) {
            int cur = q.front(); q.pop();

            for (int ncur : {cur - 1, cur + 1, cur * 2}) {
                if (ncur == k) {
                    flag = true;
                    ret = mov;

                    break;
                }

                if (0 <= ncur && ncur <= 500000) {
                    if (!visited[mov % 2][ncur]) {
                        visited[mov % 2][ncur] = true;
                        q.push(ncur);
                    }
                }
            }

            if (flag) break;
        }

        mov++;

        if (flag) break;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    if (n == k) {
        cout << 0;
    }
    else {
        bfs(n);
        cout << ret;
    }

    return 0;
}
