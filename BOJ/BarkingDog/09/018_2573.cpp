#include<iostream>
#include<tuple> //tie
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int n, m, ret, t, a[301][301], temp[301][301];
bool visited[301][301];

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        if (a[ny][nx] > 0 && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }

    return;
}

void melt() {
    fill(&temp[0][0], &temp[0][0] + 301 * 301, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > 0) {
                int sea_cnt = 0;

                int y, x;
                tie(y, x) = { i,j };

                for (int dir = 0; dir < 4; dir++) {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

                    if (a[ny][nx] == 0) {
                        sea_cnt++;
                    }
                }

                temp[y][x] = a[y][x] - sea_cnt;

                if (temp[y][x] < 0) temp[y][x] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = temp[i][j];
        }
    }

    return;
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

    while (true) {
        fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);
        ret = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] && !visited[i][j]) { //빙산이라면 dfs 시작
                    dfs(i, j);
                    ret++;
                }
            }
        }

        if (ret > 1) {
            cout << t;
            break;
        }
        else if (ret == 0) {
            cout << 0;
            break;
        }

        melt();

        t++;
    }

    return 0;
}
