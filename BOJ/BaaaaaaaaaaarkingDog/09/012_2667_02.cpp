#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
char a[30][30];
bool visited[30][30];
int n, ret;
string s;
vector<int> v;

int dfs(int y, int x) {
    visited[y][x] = 1;
    
    int ret = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

        if (a[ny][nx] == '1' && !visited[ny][nx]) {
            ret += dfs(ny, nx);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '1' && !visited[i][j]) {
                v.push_back(dfs(i, j));
                ret++;
            }
        }
    }

    sort(v.begin(), v.end());

    cout << ret << '\n';
    for (int i : v) cout << i << '\n';

    return 0;
}
