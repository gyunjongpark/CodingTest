#include<iostream>
#include<vector>
#define MAX 51
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
bool flag, visited[MAX][MAX];
int n, l, r, sum, cnt, a[MAX][MAX];
vector<pair<int, int>> v;

void dfs(int y, int x,vector<pair<int,int>>& v) {
    visited[y][x] = 1;
    v.push_back({ y,x });

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

        int gap = abs(a[y][x] - a[ny][nx]);
        if (!visited[ny][nx] && l <= gap && gap <= r) {
            sum += a[ny][nx];
            dfs(ny, nx, v);
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    while (true) {
        bool flag = 0; //인구 이동 발생 여부
        fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v.clear();
                sum = 0;

                if (!visited[i][j]) {
                    sum += a[i][j]; //초기 좌표의 값 더하기
                    dfs(i, j, v); //초기 좌표 vector v에 저장 -> v.size()=1이 기본
                    
                    if (v.size() == 1) continue; //기준 좌표에서 인구 이동 없다면 continue
                    else {
                        for (pair<int, int> b : v) {
                            a[b.first][b.second] = sum / v.size();
                        }
                        flag = 1; //인구 이동 발생
                    }
                }
            }
        }
        if (!flag) break; // 인구 이동 없다면 break
        else cnt++;
    }
    cout << cnt;

    return 0;
}
