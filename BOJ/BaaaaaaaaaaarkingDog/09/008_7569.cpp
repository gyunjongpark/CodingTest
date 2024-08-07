#include <iostream>
#include <tuple> //tuple, tie
#include <queue>
#include <vector>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const int dh[] = { 1, -1 };

int n, m, h, answer, a[101][101][101], ret[101][101][101];
vector<tuple<int, int, int>> tomato;

void bfs() {
    queue<tuple<int, int, int>> q;

    for (tuple<int, int, int> toma : tomato) {
        q.push(toma);
    }

    while (!q.empty()) {
        int y, x, height;
        tie(y, x, height) = q.front(); q.pop();

        //같은 높이에서 bfs 우선 진행
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue; //범위를 벗어나면 continue
            if (ret[ny][nx][height] >= 0) continue; //이미 방문한 곳이면 continue

            ret[ny][nx][height] = ret[y][x][height] + 1; //height는 고정
            q.push({ ny, nx, height });
        }

        //다른 층에 대하여 bfs
        for (int i = 0; i < 2; i++) {
            int nh = height + dh[i];

            if (nh < 0 || nh >= h) continue; //범위를 벗어나면 continue
            if (ret[y][x][nh] >= 0) continue; //이미 방문한 곳이면 continue

            ret[y][x][nh] = ret[y][x][height] + 1; //y, x는 고정
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

                if (a[i][j][height] == 1) {
                    tomato.push_back({ i, j, height }); //이미 잘 익은 토마토는 push, ret[i][j][height] = 0
                }
                else if (a[i][j][height] == 0) { //익지 않은 토마토라면
                    ret[i][j][height] = -1; //초기 상태 -1
                }
            }
        }
    }

    bfs(); //익은 토마토가 여러 개일 수 있으므로 좌표를 특정할 수 없음

    for (int height = 0; height < h; height++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ret[i][j][height] == -1) { //초기 상태에서 못 벗어난 토마토가 있다면 -1 출력
                    cout << -1;

                    return 0;
                }
                else {
                    answer = max(answer, ret[i][j][height]);
                }
            }
        }
    }

    cout << answer;

    return 0;
}
