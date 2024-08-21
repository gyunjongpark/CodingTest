#include<iostream>
#include<vector>
#include<tuple> //tie
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, a[10][10];
int ret = 101;
vector<pair<int, int>> cctv_list;

vector<pair<int, int>> spread_cctv(int cctv_num, int dir) {
    vector<pair<int, int>> ret;

    //현재 cctv가 설치된 좌표 i, j
    int i = cctv_list[cctv_num].first;
    int j = cctv_list[cctv_num].second;

    if (a[i][j] == 1) { //1번 cctv라면
        int y, x;
        tie(y, x) = { i,j };

        while (true) {
            int ny = y + dy[dir]; //정해진 dir 한 방향으로만 탐색한다
            int nx = x + dx[dir]; //dir은 spread_cctv 밖의 반복문으로 바뀌므로 신경 x

            //사무실 내에 있으면서 벽이 아니라면
            //cctv가 있는 칸(1 ~ 5) or 사각지대였지만 cctv가 밝힌 칸(7) or 사각지대(0)
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
                if (a[ny][nx] == 0) { //사각지대라면
                    a[ny][nx] = 7; //해당 cctv로 밝혀진 좌표는 7로 처리
                    ret.push_back({ ny,nx }); //좌표 저장
                }

                //벽만 아니라면 cctv는 끝까지 퍼진다
                y = ny;
                x = nx;
            }
            else break;
        }
    }
    else if (a[i][j] == 2) {
        for (int d = 0; d <= 2; d+=2) {
            int y, x;
            tie(y, x) = { i,j };

            while (true) {
                int ny = y + dy[(dir + d) % 4];
                int nx = x + dx[(dir + d) % 4];

                if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 7;
                        ret.push_back({ ny,nx });
                    }

                    y = ny;
                    x = nx;
                }
                else break;
            }
        }
    }
    else if (a[i][j] == 3) {
        for (int d = 0; d < 2; d++) {
            int y, x;
            tie(y, x) = { i,j };

            while (true) {
                int ny = y + dy[(dir + d) % 4];
                int nx = x + dx[(dir + d) % 4];

                if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 7;
                        ret.push_back({ ny,nx });
                    }

                    y = ny;
                    x = nx;
                }
                else break;
            }
        }
    }
    else if (a[i][j] == 4) {
        for (int d = 0; d < 3; d++) {
            int y, x;
            tie(y, x) = { i,j };

            while (true) {
                int ny = y + dy[(dir + d) % 4];
                int nx = x + dx[(dir + d) % 4];
                                
                if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 7;
                        ret.push_back({ ny,nx });
                    }
                    y = ny;
                    x = nx;
                }
                else break;
            }
        }
    }
    else if (a[i][j] == 5) {
        for (int d = 0; d < 4; d++) {
            int y, x;
            tie(y, x) = { i,j };

            while (true) {
                int ny = y + dy[(dir + d) % 4];
                int nx = x + dx[(dir + d) % 4];
                
                if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 7;
                        ret.push_back({ ny,nx });
                    }
                    y = ny;
                    x = nx;
                }
                else break;
            }
        }
    }

    return ret;
}

void dfs(int cctv_num) {
    if (cctv_num == cctv_list.size()) { //모든 cctv를 돌렸다면
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) cnt++; //사각지대의 크기를 센다
            }
        }

        ret = min(ret, cnt);

        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        vector<pair<int, int>> spreaded = spread_cctv(cctv_num, dir); //cctv의 번호, 방향에 맞춰 감시 구역을 퍼뜨린다
        dfs(cctv_num + 1);
        for (pair<int, int> s : spreaded) a[s.first][s.second] = 0; //원상 복구
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            
            if (a[i][j] != 0 && a[i][j] != 6) { //cctv라면
                cctv_list.push_back({ i,j });
            }
        }
    }

    dfs(0); //0번째 cctv부터 시뮬레이션 시작

    cout << ret;

    return 0;
}
