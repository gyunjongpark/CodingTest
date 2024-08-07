#include<iostream>
#include<vector>
#include<queue>
#include<tuple> //tie
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
const int INF = 1e9;
int ret, t, n, m, fire_visited[1001][1001], s_visited[1001][1001];
char a[1001][1001];
string s;
pair<int, int> sPos; //상근이는 한 명
vector<pair<int, int>> firePos; //불은 여러 곳에서 발생할 수 있다

void fire_bfs() {
    for (pair<int, int> fire : firePos) {
        fire_visited[fire.first][fire.second] = 1; //방문 처리
    }

    queue<pair<int, int>> q;
    for (pair<int, int> fire : firePos) {
        q.push(fire);
    }

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue; //범위를 벗어났다면 continue

            //이미 불이 퍼졌거나 벽이라면 continue
            if (fire_visited[ny][nx] != INF || a[ny][nx] == '#') continue;

            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            q.push({ ny,nx });
        }
    }

    return;
}

void s_bfs(int y, int x) { //상근이는 한 명
    s_visited[y][x] = 1;

    queue<pair<int, int>> q;
    q.push({ y,x });

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        // 탈출 조건 : 상근이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다
        if (y == 0 || y == m - 1 || x == 0 || x == n - 1) {
            ret = s_visited[y][x];

            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue; //범위를 벗어났다면
            if (fire_visited[ny][nx] <= s_visited[y][x] + 1) continue; //이미 불이 먼저 퍼졌다면
            if (s_visited[ny][nx] || a[ny][nx] == '#') continue; //벽이라면

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
        // j_visited와 비교해서 최솟값이 살아남으므로 maximum INF로 초기화
        fill(&fire_visited[0][0], &fire_visited[0][0] + 1001 * 1001, INF);
        fill(&s_visited[0][0], &s_visited[0][0] + 1001 * 1001, 0);
        firePos.clear();
        ret = 0;

        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            cin >> s;

            for (int j = 0; j < n; j++) {
                a[i][j] = s[j];

                if (a[i][j] == '@') {
                    sPos = { i,j }; //상근이 좌표 지정
                }
                else if (a[i][j] == '*') {
                    firePos.push_back({ i,j });
                }
            }
        }

        fire_bfs(); //불이 여러 곳에서 발생할 수 있으므로 좌표를 특정할 수 없음
        s_bfs(sPos.first, sPos.second); //상근이는 한 명이다

        if (ret) {
            cout << ret << '\n';
        }
        else {
            cout << "IMPOSSIBLE" << '\n';
        }
    }

    return 0;
}
