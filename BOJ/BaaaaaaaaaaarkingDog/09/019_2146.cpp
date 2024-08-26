#include<iostream>
#include<queue>
#include<tuple> //pair
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
bool visited[101][101];
int n, a[101][101];
int ret = 10001;

void label_land(int y, int x, int cnt) {
    a[y][x] = cnt; //labeling

    queue<pair<int, int>> q;
    q.push({ y,x });

    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            if (a[ny][nx] == 1) {
                a[ny][nx] = cnt;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

void bfs(int num) { //섬의 번호를 인자로 받는다
    //visited 처리
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == num) { //섬이라면
                visited[i][j] = 1;
            }
        }
    }

    //queue 생성, q.push 과정
    queue<pair<pair<int, int>, int>> q; //q<좌표(y,x),두 섬 사이의 거리>
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == num) { //같은 섬이라면
                q.push({ { i,j }, 0 }); //섬 내에서의 dist는 0으로 초기화
            }
        }
    }

    while (!q.empty()) {
        int y, x, dist;
        tie(y, x) = q.front().first; dist = q.front().second; q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            //바다도 아니고 자신의 섬도 아니라면... 다른 섬에 도착한 것이다!
            if (a[ny][nx] != 0 && a[ny][nx] != num) {
                visited[ny][nx] = 1;
                ret = min(ret, dist); //최소 거리 갱신
                return; //다리를 놓았으므로 return
            }

            //바다라면
            if (a[ny][nx] == 0 && !visited[ny][nx]) {
                visited[ny][nx] = 1;
                q.push({ { ny,nx }, dist + 1 });
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int cnt = 2; //섬을 구분하기 위한 라벨링 변수 cnt

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) { //섬이라면
                label_land(i, j, cnt); //라벨링 시작
                cnt++; //cnt를 증가시켜 다른 섬들과 구별
            }
        }
    }

    for (int i = 2; i < cnt; i++) {
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        bfs(i);
    }

    cout << ret;

    return 0;
}
