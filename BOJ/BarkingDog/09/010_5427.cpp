#include<iostream>
#include<vector>
#include<queue>
#include<tuple> //tie
#include<climits> //INT_MAX
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int ret, t, n, m, fire_visited[1001][1001], s_visited[1001][1001];
char a[1001][1001];
string s;
pair<int, int> sPos;
vector<pair<int, int>> firePos;

void fire_bfs() {
    for (pair<int, int> fire : firePos) {
        fire_visited[fire.first][fire.second] = 1;
    }

    queue<pair<int, int>> q;
    for (pair<int, int> fire : firePos) {
        q.push(fire);
    }

    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue; //범위를 벗어나면
            if (fire_visited[ny][nx] != INT_MAX || a[ny][nx] == '#') continue; //이미 불이 번진 곳이거나 벽이라면

            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            q.push({ ny,nx });
        }
    }

    return;
}

void s_bfs(int y, int x) {
    s_visited[y][x] = 1;

    queue<pair<int, int>> q;
    q.push({ y,x });

    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        //탈출 조건
        if (y == 0 || y == m - 1 || x == 0 || x == n - 1) {
            ret = s_visited[y][x];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue; //범위를 벗어나면
            if (fire_visited[ny][nx] <= s_visited[y][x] + 1) continue; //이미 불이 먼저 퍼졌다면
            if (s_visited[ny][nx] || a[ny][nx] == '#') continue; //이미 방문했거나 벽이라면

            s_visited[ny][nx] = s_visited[y][x] + 1;
            q.push({ ny,nx });
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        fill(&fire_visited[0][0], &fire_visited[0][0] + 1001 * 1001, INT_MAX);
        fill(&s_visited[0][0], &s_visited[0][0] + 1001 * 1001, 0);
        firePos.clear();
        ret = 0;

        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            cin >> s;

            for (int j = 0; j < n; j++) {
                a[i][j] = s[j];

                if (a[i][j] == '@') {
                    sPos = { i,j };
                }
                else if (a[i][j] == '*') {
                    firePos.push_back({ i,j });
                }
            }
        }

        fire_bfs();
        s_bfs(sPos.first, sPos.second);

        if (ret) cout << ret << '\n';
        else cout << "IMPOSSIBLE" << '\n';
    }

    return 0;
}
