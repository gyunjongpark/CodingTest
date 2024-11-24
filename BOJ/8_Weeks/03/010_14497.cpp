#include<iostream>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int visited[301][301], n, m, sy, sx, ey, ex, ret;
char a[301][301];
string s;

void bfs(int sy, int sx) {
    visited[sy][sx] = 1;

    queue<pair<int, int>> q;
    q.push({ sy,sx });

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;            

            if (!visited[ny][nx]) {
                if (a[ny][nx] == '1') {
                    visited[ny][nx] = 1;
                    a[ny][nx] = '0';
                }
                else if (a[ny][nx] == '0') {
                    visited[ny][nx] = 1;
                    q.push({ ny,nx });
                }
                else if (a[ny][nx] == '#') {
                    visited[ny][nx] = 1;
                    break;
                }
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> sy >> sx >> ey >> ex;

    sy--, sx--, ey--, ex--;

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    while (true) {
        fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);

        bfs(sy, sx);

        ret++;

        if (visited[ey][ex]) {
            cout << ret;
            break;
        }
    }

    return 0;
}
