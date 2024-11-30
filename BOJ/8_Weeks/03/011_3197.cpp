#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, ret;
char a[1501][1501];
bool visited[1501][1501], water_visited[1501][1501];
string s;
vector<pair<int, int>> swan;
queue<pair<int, int>> water, next_water;
queue<pair<int, int>> swan_q, next_swan_q;

bool meet() {
    while (!swan_q.empty()) {
        pair<int, int> cur = swan_q.front(); swan_q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (!visited[ny][nx]) {
                visited[ny][nx] = true;

                if (a[ny][nx] == 'L') return true; //두 백조가 만났다면
                else if (a[ny][nx] == '.') swan_q.push({ ny,nx });
                else if (a[ny][nx] == 'X') next_swan_q.push({ ny,nx });
            }
        }
    }

    return false;
}

void melt() {
    while (!water.empty()) {
        pair<int, int> cur = water.front(); water.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (!water_visited[ny][nx]) {
                water_visited[ny][nx] = true;

                if (a[ny][nx] == 'X') {
                    a[ny][nx] = '.'; //얼음 녹이기
                    next_water.push({ ny,nx });
                }
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];

            if (a[i][j] != 'X') { //물이 있기 때문에 백조가 존재할 수 있다
                water.push({ i, j });
                water_visited[i][j] = true;
            }

            if (a[i][j] == 'L') {
                swan.push_back({ i, j });
            }
        }
    }

    visited[swan[0].first][swan[0].second] = true;
    swan_q.push(swan[0]);

    while (true) {
        if (meet()) {
            cout << ret;
            break;
        }

        melt();

        swap(swan_q, next_swan_q);
        swap(water, next_water);

        ret++;
    }

    return 0;
}
