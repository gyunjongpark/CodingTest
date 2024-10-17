#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Tomato {
    int y, x, height;
};
vector<Tomato> tomato;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
const int dh[] = { 1,-1 };
int n, m, h, answer, a[101][101][101], visited[101][101][101];
bool flag;

void bfs() {
    for (Tomato toma : tomato) {
        visited[toma.y][toma.x][toma.height] = 0;
    }

    queue<Tomato> q;
    for (Tomato toma : tomato) {
        q.push(toma);
    }

    while (!q.empty()) {
        Tomato cur = q.front(); q.pop();

        //같은 층 bfs 진행
        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int nh = cur.height; //height는 고정

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue; //범위를 벗어나면 continue

            //애초에 토마토가 들어있지 않았거나(a[i][j][height] = -1 -> visited[i][j][height] = 0)
            //날짜가 지나서 익은 토마토라면 continue
            if (visited[ny][nx][nh] >= 0) continue;

            visited[ny][nx][nh] = visited[cur.y][cur.x][cur.height] + 1;
            q.push({ ny, nx, nh });
        }

        //다른 층 bfs 진행
        for (int i = 0; i < 2; i++) {
            int ny = cur.y; //y, x는 고정
            int nx = cur.x; //y, x는 고정
            int nh = cur.height + dh[i];

            if (nh < 0 || nh >= h) continue; //범위를 벗어나면 continue

            //애초에 토마토가 들어있지 않았거나(a[i][j][height] = -1 -> visited[i][j][height] = 0)
            //날짜가 지나서 익은 토마토라면 continue
            if (visited[cur.y][cur.x][nh] >= 0) continue;

            visited[ny][nx][nh] = visited[cur.y][cur.x][cur.height] + 1; //y, x는 고정
            q.push({ ny,nx,nh });
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n >> h;

    for (int height = 0; height < h; height++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j][height];

                if (a[i][j][height] == 1) { //초기에 이미 익은 토마토라면
                    tomato.push_back({ i, j, height });
                }
                else if (a[i][j][height] == 0) { //익지 않은 토마토
                    visited[i][j][height] = -1;
                }
            }
        }
    }

    bfs();

    for (int height = 0; height < h; height++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j][height] == -1) { //bfs 이후 익지 않은 토마토가 있다면
                    flag = true;
                }
                else {
                    answer = max(answer, visited[i][j][height]); //모두 익어야 하므로 maximum 출력
                }
            }
        }
    }

    if (flag) cout << -1;
    else cout << answer;

    return 0;
}
