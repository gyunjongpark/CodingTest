#include<iostream>
#include<climits> //INT_MIN
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int dp[501][501], board[501][501], n;
int ret = INT_MIN;

//판다가 이동할 수 있는 칸의 수의 최댓값 = dfs로 탐색 후 각 좌표에서의 최대 깊이를 dp에 저장
int recur(int y, int x) {
    if (dp[y][x]) return dp[y][x];

    dp[y][x] = 1; //init

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

        if (board[ny][nx] > board[y][x]) {
            dp[y][x] = max(dp[y][x], recur(ny, nx) + 1);
        }
    }

    return dp[y][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            recur(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret = max(ret, dp[i][j]);
        }
    }

    cout << ret;

    return 0;
}
