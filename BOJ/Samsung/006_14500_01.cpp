#include<iostream>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, a[501][501], ret;
bool visited[501][501];
vector<int> v;

void combi_dfs(int y, int x, vector<int>& v) {
    if (v.size() == 4) {
        int sum = 0;

        for (int i = 0; i < 4; i++) {
            sum += v[i];
        }

        ret = max(ret, sum);

        return;
    }

    visited[y][x] = 1;
    v.push_back(a[y][x]);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        if (!visited[ny][nx]) {
            combi_dfs(ny, nx, v);
        }
    }

    visited[y][x] = 0; //원상 복구
    v.pop_back(); //원상 복구
}

//combi_dfs는 ㅗ,ㅜ,ㅏ,ㅓ로 뻗어나갈 수 없기 때문에 배열의 값을 직접 더해 블록을 완성한다
//4가지 케이스에 대해서 모두 max 연산을 거친다 (else if x)
void check_extra_shape(int y, int x) {
    if (y >= 1 && x >= 1 && x + 1 < m) {
        ret = max(ret, a[y][x] + a[y - 1][x] + a[y][x - 1] + a[y][x + 1]); //ㅗ
    }

    if (y + 1 < n && x >= 1 && x + 1 < m) {
        ret = max(ret, a[y][x] + a[y + 1][x] + a[y][x - 1] + a[y][x + 1]); //ㅜ
    }

    if (y >= 1 && y + 1 < n && x + 1 < m) {
        ret = max(ret, a[y][x] + a[y - 1][x] + a[y + 1][x] + a[y][x + 1]); //ㅏ
    }

    if (y >= 1 && y + 1 < n && x >= 1) {
        ret = max(ret, a[y][x] + a[y - 1][x] + a[y + 1][x] + a[y][x - 1]); //ㅓ
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
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            combi_dfs(i, j, v); //이어진 4개의 좌표를 선택하는 경우의 수
            check_extra_shape(i, j);
        }
    }

    cout << ret;

    return 0;
}
