#include<iostream>
#include<vector>
#include<queue>
#include<tuple> //tie
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
const int INF = 1e9;
int ret, n, m, fire_visited[1001][1001], j_visited[1001][1001];
char a[1001][1001];
string s;
pair<int, int> jPos;
vector<pair<int, int>> firePos;

void fire_bfs() {
    for (pair<int, int> fire : firePos) {
        fire_visited[fire.first][fire.second] = 1;
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

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            //이미 불이 번진 곳이거나 벽이라면 continue
            if (fire_visited[ny][nx] != INF || a[ny][nx] == '#') continue;

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

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        //지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다
        if (y == 0 || y == n - 1 || x == 0 || x == m - 1) {
            ret = j_visited[y][x]; //최종 결과 ret에 저장

            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (fire_visited[ny][nx] <= j_visited[y][x] + 1) continue; //이미 불이 먼저 퍼졌다면
            if (j_visited[ny][nx] || a[ny][nx] == '#') continue;

            j_visited[ny][nx] = j_visited[y][x] + 1;
            q.push({ ny,nx });
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //j_visited와 비교해서 최솟값이 살아남으므로 maximum INF로 초기화
    fill(&fire_visited[0][0], &fire_visited[0][0] + 1001 * 1001, INF);

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

    fire_bfs(); //시작점이 여러 개인 bfs
    j_bfs(jPos.first, jPos.second);

    if (ret) {
        cout << ret;
    }
    else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
