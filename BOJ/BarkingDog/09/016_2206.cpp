#include<iostream>
#include<queue>
using namespace std;

struct info {
    int y, x;
    bool broken;
};

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int visited[1001][1001][2], n, m; //visited[y][x][벽을 부셨는지 여부]
char a[1001][1001];
string s;

int bfs() {
    visited[0][0][true] = 1; //시작하는 칸과 끝나는 칸도 포함해서 센다

    queue<info> q;
    q.push({ 0,0,0 }); //초기 좌표 push

    while (!q.empty()) {
        info cur = q.front(); q.pop();

        if (cur.y == n - 1 && cur.x == m - 1) {
            return visited[cur.y][cur.x][cur.broken];
        }

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            bool nb = cur.broken;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            //broken 여부와 관계없이 a[ny][nx]가 0이면서 방문하지 않았다면 broken 상태를 유지하면서 bfs를 진행한다
            if (a[ny][nx] == '0' && !visited[ny][nx][nb]) {
                visited[ny][nx][nb] = visited[cur.y][cur.x][cur.broken] + 1;
                q.push({ ny,nx,nb });
            }

            //위 if문에서 벽에 막혔을 경우 딱 한번 벽을 부술 수 있다
            //벽을 부술 기회가 남아있고, a[ny][nx]가 1이면서 방문하지 않았다면
            if (!cur.broken && a[ny][nx] == '1' && !visited[ny][nx][true]) {
                visited[ny][nx][true] = visited[cur.y][cur.x][cur.broken] + 1;
                q.push({ ny,nx,true }); //이후 bfs는 broken = true인 채로 진행
            }
        }
    }

    return -1; //queue가 비었는데 목적지에 도달하지 못했다면 -1 반환
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
