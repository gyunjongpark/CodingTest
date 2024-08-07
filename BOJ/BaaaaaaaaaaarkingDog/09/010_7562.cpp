#include<iostream>
#include<queue>
#include<tuple> //tie
using namespace std;

const int dy[] = { -2,-1,1,2,2,1,-1,-2 };
const int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int t, n, sy, sx, ey, ex, visited[301][301];

void bfs(int y, int x) {
    visited[y][x] = 1;

    queue<pair<int, int>> q;
    q.push({ y,x });

    while (q.size()) {
        int y, x;

        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            if (!visited[ny][nx]) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;

    while (t--) {        
        fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);
        
        cin >> n >> sy >> sx >> ey >> ex;

        bfs(sy, sx);
        
        cout << visited[ey][ex] - 1 << '\n';
    }

    return 0;
}
