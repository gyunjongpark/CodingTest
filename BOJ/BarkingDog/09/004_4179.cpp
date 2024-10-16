#include<iostream>
#include<vector>
#include<queue>
#include<tuple> //tie
#include<climits> //INT_MAX
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int ret, n, m, fire_visited[1001][1001], j_visited[1001][1001];
char a[1001][1001];
string s;
pair<int, int> jPos; //지훈이는 한 명
vector<pair<int, int>> firePos; //불은 여러 곳에서 발생할 수 있다

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

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue; //범위를 벗어나면 continue
            if (fire_visited[ny][nx] != INT_MAX || a[ny][nx] == '#') continue; //이미 불이 번졌거나 벽이라면 continue

            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            q.push({ ny,nx });
        }
    }

    return;
}

void j_bfs(int y, int x) {
    j_visited[y][x] = 1;

    queue<pair<int, int>> q;
    q.push({ y,x });

    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        if (y == 0 || y == n - 1 || x == 0 || x == m - 1) { //탈출 조건
            ret = j_visited[y][x];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue; //범위를 벗어나면 continue
            if (fire_visited[ny][nx] <= j_visited[y][x] + 1) continue; //먼저 불에 탔다면 continue
            if (j_visited[ny][nx] || a[ny][nx] == '#') continue; //이미 방문했거나 벽이라면 continue

            j_visited[ny][nx] = j_visited[y][x] + 1;
            q.push({ ny,nx });
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(&fire_visited[0][0], &fire_visited[0][0] + 1001 * 1001, INT_MAX);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];

            if (a[i][j] == 'J') {
                jPos = { i,j };
            }
            else if (a[i][j] == 'F') {
                firePos.push_back({ i,j });
            }
        }
    }

    fire_bfs();
    j_bfs(jPos.first, jPos.second);

    if (ret) cout << ret;
    else cout << "IMPOSSIBLE";

    return 0;
}
