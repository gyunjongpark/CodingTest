#include<iostream>
#include<queue>
#include<tuple> //tuple, tie
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int visited[1001][1001][2], n, m; //dist[y][x][벽을 부셨는지 여부]
char a[1001][1001];
string s;

int bfs() {
    visited[0][0][0] = visited[0][0][1] = 1; //시작하는 칸과 끝나는 칸도 포함해서 센다

    queue<tuple<int, int, int>> q;
    q.push({ 0,0,0 }); //초기 좌표 push

    while (!q.empty()) {
        int y, x, broken;
        tie(y, x, broken) = q.front(); q.pop();

        if (y == n - 1 && x == m - 1) { //종료 조건
            return visited[y][x][broken];
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            //broken 여부와 관계없이 a[ny][nx]가 0이면서 방문하지 않았다면 bfs를 진행한다
            if (a[ny][nx] == '0' && !visited[ny][nx][broken]) {
                visited[ny][nx][broken] = visited[y][x][broken] + 1;
                q.push({ ny,nx,broken });
            }

            //위 if문에서 벽에 막혔을 경우 딱 한번 벽을 부술 수 있다
            //bfs 자체가 최단 경로를 구하는 방법이므로 모든 벽을 선택하는 경우를 포함한 결과를 반환한다

            //벽을 부술 기회가 남아있고, a[ny][nx]가 1이면서 방문하지 않았다면
            if (!broken && a[ny][nx] == '1' && !visited[ny][nx][1]) {
                visited[ny][nx][1] = visited[y][x][broken] + 1;
                q.push({ ny,nx,1 }); //이후 bfs는 broken = 1인 채로 진행되므로 처음 if문만 유효하게 된다
            }
        }
    }

    return -1; //queue가 비었는데 목적지에 도달하지 못하면 -1 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    cout << bfs();

    return 0;
}