#include<iostream>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, a[101][101];
bool visited[101][101];

void dfs(int y, int x, int height) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (a[ny][nx] > height && !visited[ny][nx]) {
            dfs(ny, nx, height);
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int maxVal = 1; //아무 지역도 물에 잠기지 않을 수도 있다
    int k = 100;

    while (k--) {
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0); //initialize
        int ret = 0; //initialize

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] > k && !visited[i][j]) {
                    dfs(i, j, k); ret++;
                }
            }
        }

        maxVal = max(maxVal, ret);
    }

    cout << maxVal;

    return 0;
}
