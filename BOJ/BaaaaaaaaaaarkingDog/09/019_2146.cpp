#include<iostream>
#include<queue>
#include<tuple> //pair
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, a[101][101];
int ret = 10001;
bool visited[101][101];

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

            if (a[ny][nx] == 1) { //아직 라벨링을 하지 않은 섬이라면
                a[ny][nx] = cnt;
                q.push({ ny,nx }); //라벨링하고 push
            }
        }
    }

    return;
}

void bfs(int num) { //섬의 번호를 인자로 받는다
    queue<pair<pair<int, int>, int>> q; //queue<좌표(y,x),두 섬 사이의 거리>

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == num) { //섬에서 출발
                visited[i][j] = 1;
                q.push({ { i,j }, 0 });
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

            //바다도 아니고 자신의 섬도 아닌 다른 섬에 도착한다면
            if (a[ny][nx] != 0 && a[ny][nx] != num) {
                ret = min(ret, dist);
                return; //다리를 놓았으므로 return
            }

            if (!visited[ny][nx]) {
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
                label_land(i, j, cnt);
                cnt++; //cnt를 증가시켜 다른 섬들과 구별하기
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
