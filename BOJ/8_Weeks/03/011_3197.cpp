#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int n, m, ret;
string s;
char a[1501][1501];
bool visited[1501][1501], water_visited[1501][1501];
vector<pair<int, int>> swan;
queue<pair<int, int>> water, next_water;
queue<pair<int, int>> swan_q, next_swan_q;

bool can_meet() {
    while (!swan_q.empty()) {
        int y = swan_q.front().first;
        int x = swan_q.front().second;

        swan_q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;

            if (a[ny][nx] == 'L') return true; //백조끼리 만날 때

            visited[ny][nx] = true;

            if (a[ny][nx] == '.') {
                swan_q.push({ ny, nx });
            }
            else if (a[ny][nx] == 'X') {
                next_swan_q.push({ ny, nx });
            }
        }
    }

    return false;
}

void melt_ice() {
    while (!water.empty()) {
        int y = water.front().first;
        int x = water.front().second;

        water.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || water_visited[ny][nx]) continue;

            if (a[ny][nx] == 'X') {
                a[ny][nx] = '.';
                next_water.push({ ny, nx });
            }

            water_visited[ny][nx] = true;
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

            if (a[i][j] != 'X') {
                water.push({ i, j });
                water_visited[i][j] = true;
            }

            if (a[i][j] == 'L') {
                swan.push_back({ i, j });
            }
        }
    }

    swan_q.push(swan[0]);
    visited[swan[0].first][swan[0].second] = true;

    while (true) {
        if (can_meet()) {
            cout << ret;
            break;
        }

        melt_ice();

        swap(swan_q, next_swan_q);
        swap(water, next_water);

        ret++;
    }

    return 0;
}
