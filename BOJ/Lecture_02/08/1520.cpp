#include<iostream>
#include<vector>
#define INF 1e9
#define MAX 504
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int a[MAX][MAX], n, m;

int recur(int y, int x) {
    if (y == n - 1 && x == m - 1) return 1;
    
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        if (a[ny][nx] < a[y][x]) {
            ret += recur(ny, nx);
        }
    }

    return ret;
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
    cout << recur(0, 0);

    return 0;
}
