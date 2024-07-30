#include<iostream>
#include<vector>
#include<queue>
#include<tuple> //pair
#define MAX 1001
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
const int INF = 1e9;
int ret, n, m, fire_visited[MAX][MAX], j_visited[MAX][MAX];
char a[MAX][MAX];
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

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (fire_visited[ny][nx] !=INF || a[ny][nx] == '#') continue;

            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            q.push({ ny,nx });
        }
    }

    return;
}

void j_bfs(int y, int x) { //지훈이는 한 명
    j_visited[y][x] = 1;

    queue<pair<int, int>> q;
    q.push({ y,x });

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        if (y == 0 || y == n - 1 || x == 0 || x == m - 1) { //탈출 조건
            ret = j_visited[y][x];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (fire_visited[ny][nx] <= j_visited[y][x] + 1) continue; //먼저 불에 탔다면 continue
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

    fill(&fire_visited[0][0], &fire_visited[0][0] + MAX * MAX, INF); //j_visited와 비교해서 최솟값이 살아남으므로 INF 초기화

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];

            if (a[i][j] == 'J') {                
                jPos = { i,j }; //지훈이 좌표 지정
            }
            else if (a[i][j] == 'F') {
                firePos.push_back({ i,j });
            }
        }
    }

    fire_bfs(); //불이 여러 곳에서 발생할 수 있으므로 좌표를 특정할 수 없음
    j_bfs(jPos.first, jPos.second); //지훈이는 한 명이다

    if (ret) cout << ret;
    else cout << "IMPOSSIBLE";

    return 0;
}
