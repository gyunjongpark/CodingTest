#include<iostream>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
char a[101][101];
bool visited[101][101];
int n, ret, ret_dis;
string s;

void dfs_R(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

        if (a[ny][nx] == 'R' && !visited[ny][nx]) {
            dfs_R(ny, nx);
        }
    }

    return;
}

void dfs_G(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

        if (a[ny][nx] == 'G' && !visited[ny][nx]) {
            dfs_G(ny, nx);
        }
    }

    return;
}

void dfs_B(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

        if (a[ny][nx] == 'B' && !visited[ny][nx]) {
            dfs_B(ny, nx);
        }
    }

    return;
}

void dfs_R_G(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

        if ((a[ny][nx] == 'R' || a[ny][nx] == 'G') && !visited[ny][nx]) {
            dfs_R_G(ny, nx);
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j];
        }
    }

    //n^2 * dfs(n^2) = n^4 -> n은 100 이하이므로 1초 간당간당하게 통과
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'R' && !visited[i][j]) {
                dfs_R(i, j); ret++;
            }
            else if (a[i][j] == 'G' && !visited[i][j]) {
                dfs_G(i, j); ret++;
            }
            else if (a[i][j] == 'B' && !visited[i][j]) {
                dfs_B(i, j); ret++;
            }
        }
    }

    fill(&visited[0][0], &visited[0][0] + 101 * 101, 0); //init

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((a[i][j] == 'R' || a[i][j] == 'G') && !visited[i][j]) {
                dfs_R_G(i, j); ret_dis++;
            }
            else if (a[i][j] == 'B' && !visited[i][j]) {
                dfs_B(i, j); ret_dis++;
            }
        }
    }

    cout << ret << ' ' << ret_dis;

    return 0;
}
