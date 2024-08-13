#include<iostream>
#include<tuple> //tuple, tie
#include<queue>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
const int dh[] = { 1,-1 };
int l, r, c, answer, visited[31][31][31];
char a[31][31][31];
string s;
tuple<int, int, int> sPos, ePos;

void bfs(int y, int x, int h) {
    visited[y][x][h] = 1;

    queue<tuple<int, int, int>> q;
    q.push({ y,x,h });

    while (!q.empty()) {
        int y, x, height;
        tie(y, x, height) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (a[ny][nx][height] == '#') continue;

            if (!visited[ny][nx][height]) {
                visited[ny][nx][height] = visited[y][x][height] + 1;
                q.push({ ny,nx,height });
            }
        }

        for (int i = 0; i < 2; i++) {
            int nh = height + dh[i];

            if (nh < 0 || nh >= l) continue; //범위를 벗어나면 continue
            if (a[y][x][nh] == '#') continue;

            if (!visited[y][x][nh]) {
                visited[y][x][nh] = visited[y][x][height] + 1; //y, x는 고정
                q.push({ y, x, nh });
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        cin >> l >> r >> c;

        if (l == 0 && r == 0 && c == 0) break;

        fill(&visited[0][0][0], &visited[0][0][0] + 31 * 31 * 31, 0);//init

        for (int k = 0; k < l; k++) {
            for (int i = 0; i < r; i++) {
                cin >> s;

                for (int j = 0; j < c; j++) {
                    a[i][j][k] = s[j];
                    if (a[i][j][k] == 'S') {
                        sPos = { i,j,k };
                    }
                    if (a[i][j][k] == 'E') {
                        ePos = { i,j,k };
                    }
                }
            }
        }

        bfs(get<0>(sPos), get<1>(sPos), get<2>(sPos));


        if (!visited[get<0>(ePos)][get<1>(ePos)][get<2>(ePos)]) cout << "Trapped!" << '\n';
        else cout << "Escaped in " << visited[get<0>(ePos)][get<1>(ePos)][get<2>(ePos)] - 1 << " minute(s)." << '\n';
    }

    return 0;
}
