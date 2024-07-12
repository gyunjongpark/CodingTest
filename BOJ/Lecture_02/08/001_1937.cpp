#include<iostream>
#include<vector>
#define INF 1e9
#define MAX 504
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
vector<vector<int>> dp;
int answer = -INF;
int a[MAX][MAX], n;

/* 시간 초과 O(4*(n^2))

int recur(int y, int x) {
    int ret = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

        if (a[ny][nx] > a[y][x]) {
            ret = max(ret, recur(ny,nx) + 1);
        }
    }
    return ret;
}

*/

//(y,x)가 정해질 때 최악의 경우 O(n^2)가 걸릴 수 있지만, 만약 그렇다면 나머지 y,x에 대해서는 O(1)이 소요된다
//메모이제이션으로 굳어진 좌표값을 바로 사용하기 때문이다
int recur(int y, int x) {
    if (dp[y][x]) return dp[y][x];

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

        if (a[ny][nx] > a[y][x]) {
            dp[y][x] = max(dp[y][x], recur(ny, nx) + 1);
        }
    }

    return dp[y][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    dp.resize(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            recur(i, j); //dp[i][j] 채우기, 각 i,j에 대하여 평균적으로 O(1)이 소요된다
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer = max(answer, dp[i][j]);
        }
    }
    cout << answer + 1;

    return 0;
}
