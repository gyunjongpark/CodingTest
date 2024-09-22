#include<iostream>
#include<tuple> //tuple, tie
#include<queue>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
const int dh[] = { 1,-1 };
int n, m, h, answer, a[101][101][101], visited[101][101][101];
vector<tuple<int, int, int>> tomato;

void bfs() {
    for (tuple<int, int, int> toma : tomato) {
        visited[get<0>(toma)][get<1>(toma)][get<2>(toma)] = 0;
    }

    queue<tuple<int, int, int>> q;
    for (tuple<int, int, int> toma : tomato) {
        q.push(toma);
    }

    while (!q.empty()) {
        int y, x, height;
        tie(y, x, height) = q.front(); q.pop();

        //같은 층 bfs 진행(퍼지는 것은 동일하기 때문에 순서가 바뀌어도 상관없다)
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue; //범위를 벗어나면 continue

            //애초에 토마토가 들어있지 않았거나(a[i][j][height] = -1 -> ret[i][j][height] = 0), 날짜가 지나서 익은 토마토라면
            if (visited[ny][nx][height] >= 0) continue;

            visited[ny][nx][height] = visited[y][x][height] + 1; //height는 고정
            q.push({ ny, nx, height });
        }

        //다른 층 bfs 진행(퍼지는 것은 동일하기 때문에 순서가 바뀌어도 상관없다)
        for (int i = 0; i < 2; i++) {
            int nh = height + dh[i];

            if (nh < 0 || nh >= h) continue; //범위를 벗어나면 continue

            //애초에 토마토가 들어있지 않았거나(a[i][j][height] = -1 -> ret[i][j][height] = 0), 날짜가 지나서 익은 토마토라면
            if (visited[y][x][nh] >= 0) continue;

            visited[y][x][nh] = visited[y][x][height] + 1; //y, x는 고정
            q.push({ y, x, nh });
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

                if (a[i][j][height] == 1) { //초기에 이미 익은 토마토라면 push
                    tomato.push_back({ i, j, height });
                }
                else if (a[i][j][height] == 0) { //익지 않은 토마토라면
                    visited[i][j][height] = -1; //초기 상태 -1
                }
            }
        }
    }

    bfs(); //익은 토마토가 여러 개일 수 있으므로 좌표를 특정할 수 없음 -> 시작점이 여러 곳인 bfs

    for (int height = 0; height < h; height++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j][height] == -1) { //토마토가 모두 익지 못하는 상황이면 -1 출력
                    cout << -1;

                    return 0;
                }
                else {
                    answer = max(answer, visited[i][j][height]); //모두 익어야 하므로 maximum 출력
                }
            }
        }
    }

    cout << answer;

    return 0;
}
