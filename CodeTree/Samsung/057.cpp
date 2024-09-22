#include<iostream>
#include<climits> //INT_MAX
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, y, x, d, a[51][51];
int ret = 0;
bool visited[51][51];

void drive(int y, int x, int dir) {
    if (!visited[y][x]) {
        visited[y][x] = 1; //방문처리
        ret++;
    }
    
    for (int i = 0; i < 4; i++) { //상하좌우 반복
        dir = (dir + 3) % 4; //왼쪽으로 방향 전환

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] == 0 && !visited[ny][nx]) {
            drive(ny, nx, dir); //1번 과정 시도
            return; //조건을 만족하여 좌표가 옮겨졌다면 현재 y, x에서의 drive의 역할은 종료(후진 과정을 거치지 않는다)
        }
    }

    //y, x에서 네 방향 모두 조건을 만족하지 않을 시(더 이상의 전진이 불가능하다면) 후진 방향 설정
    int back_dir = (dir + 2) % 4; //후진 방향으로 전환

    //후진
    int ny = y + dy[back_dir];
    int nx = x + dx[back_dir];

    if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] == 0) { //후진은 visited와 관계없다
        drive(ny, nx, dir); //후진 이후 해당 좌표에서 다시 drive 실행
    }
    else return; //더 이상 후진할 수 없다면 종료
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> y >> x >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    drive(y, x, d);

    cout << ret;

    return 0;
}
