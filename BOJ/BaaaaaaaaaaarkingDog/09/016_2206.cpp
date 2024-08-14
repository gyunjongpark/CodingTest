#include<iostream>
#include<tuple> //tuple, tie
#include<queue>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
char a[1001][1001];
int dist[1001][1001][2], n, m; //dist[y][x][벽을 부쉈는지 여부. 1이라면 부쉈음을 나타냄]
string s;

int bfs() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j][0] = dist[i][j][1] = -1; //init
        }
    }
    dist[0][0][0] = dist[0][0][1] = 1; //시작하는 칸과 끝나는 칸도 포함해서 센다

    queue<tuple<int, int, int>> q;
    q.push({ 0,0,0 }); //초기 좌표 push

    while (!q.empty()) {
        int y, x, broken;
        tie(y, x, broken) = q.front(); q.pop();

        if (y == n - 1 && x == m - 1) { //종료 조건
            return dist[y][x][broken];
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            //broken 여부와 관계없이 0이면서 좌표가 방문되지만 않았다면 bfs를 진행한다
            if (a[ny][nx] == '0' && dist[ny][nx][broken] == -1) {
                dist[ny][nx][broken] = dist[y][x][broken] + 1;
                q.push({ ny,nx,broken });
            }

            //위 if문에서 벽에 막혔을 경우 딱 한번 벽을 부순다
            //bfs 자체가 최단거리를 구하는 방법이므로 모든 벽을 선택하는 경우를 포함한 결과를 반환한다
            
            //벽을 부술 기회가 있으면서 a[ny][nx]가 1이면서 방문하지 않았다면
            if (!broken && a[ny][nx] == '1' && dist[ny][nx][1] == -1) { 
                dist[ny][nx][1] = dist[y][x][broken] + 1;
                q.push({ ny,nx,1 }); //이후 bfs는 broken = 1인 채로 진행된다
            }
        }
    }

    return -1; //목적지에 도달하지 못하면 -1 반환
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
