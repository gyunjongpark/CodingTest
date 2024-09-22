#include<iostream>
#include<tuple> //tie
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, answer, a[1001][1001], visited[1001][1001];
vector<pair<int, int>> tomato;

void bfs() {
    queue <pair<int, int>> q;
    for (pair<int, int> toma : tomato) {
        q.push(toma);
    }

    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue; //범위를 벗어나면 continue

            //애초에 토마토가 들어있지 않았거나(a[i][j] = -1 -> visited[i][j] = 0), 날짜가 지나서 익은 토마토라면
            if (visited[ny][nx] >= 0) continue;

            visited[ny][nx] = visited[y][x] + 1;
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
                tomato.push_back({ i,j }); //ret[i][j] = 0
            }
            else if (a[i][j] == 0) { //익지 않은 토마토라면
                visited[i][j] = -1; //초기 상태 -1
            }
        }
    }

    bfs(); //익은 토마토가 여러 개일 수 있으므로 좌표를 특정할 수 없다 -> 시작점이 여러 곳인 bfs

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == -1) { //토마토가 모두 익지 못하는 상황이면 -1 출력
                cout << -1;

                return 0;
            }
            else {
                answer = max(answer, visited[i][j]); //모두 익어야 하므로 maximum 출력
            }
        }
    }

    cout << answer;

    return 0;
}
