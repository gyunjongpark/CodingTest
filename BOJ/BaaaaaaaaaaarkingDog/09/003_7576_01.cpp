#include<iostream>
#include<tuple> //tie
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, answer, a[1001][1001], ret[1001][1001];
vector<pair<int, int>> tomato;

void bfs() {
    queue <pair<int, int>> q;
    for (pair<int, int> toma : tomato) {
        q.push(toma);
    }

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue; //범위를 벗어나면 continue
            if (ret[ny][nx] >= 0) continue; //초기 상태의 토마토가 아니라면 continue

            ret[ny][nx] = ret[y][x] + 1;
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
                ret[i][j] = -1; //초기 상태 -1
            }
        }
    }

    bfs(); //익은 토마토 기준으로 bfs 우선 진행

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ret[i][j] == -1) { //초기 상태에서 못 벗어난 토마토가 있다면 -1 출력
                cout << -1;
                return 0;
            }
            else {
                answer = max(answer, ret[i][j]);
            }
        }
    }
    cout << answer;

    return 0;
}
