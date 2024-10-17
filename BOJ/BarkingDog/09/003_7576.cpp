#include<iostream>
#include<tuple> //tie
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, answer, a[1001][1001], visited[1001][1001];
bool flag;
vector<pair<int, int>> tomato;

void bfs() {
    queue <pair<int, int>> q;
    for (pair<int, int> toma : tomato) {
        q.push(toma);
    }

    while (!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue; //범위를 벗어나면 continue

            //애초에 토마토가 들어있지 않았거나(a[i][j] = -1 -> visited[i][j] = 0)
            //날짜가 지나서 익은 토마토라면 continue
            if (visited[ny][nx] >= 0) continue;

            //익지 않은 토마토 bfs
            visited[ny][nx] = visited[cur.first][cur.second] + 1;
            q.push({ ny,nx });
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];

            if (a[i][j] == 1) { //초기에 이미 익은 토마토라면 push
                tomato.push_back({ i,j }); //visited[i][j] = 0
            }
            else if (a[i][j] == 0) { //익지 않은 토마토
                visited[i][j] = -1;
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == -1) { //bfs 이후 익지 않은 토마토가 있다면
                flag = true;
            }
            else {
                answer = max(answer, visited[i][j]); //모두 익어야 하므로 maximum 출력
            }
        }
    }

    if (flag) cout << -1;
    else cout << answer;

    return 0;
}
