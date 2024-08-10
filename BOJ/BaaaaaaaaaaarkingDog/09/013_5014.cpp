#include<iostream>
#include<queue>
using namespace std;

int f, s, g, u, d, visited[1000001];

void bfs(int start) {
    visited[start] = 1;
    
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int here = q.front(); q.pop();

        if (here == g) break; //back tracking

        if (here + u <= f && !visited[here + u]) {
            visited[here + u] = visited[here] + 1;
            q.push(here + u);
        }

        if (here - d >= 1 && !visited[here - d]) {
            visited[here - d] = visited[here] + 1;
            q.push(here - d);
        }
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> f >> s >> g >> u >> d;

    if (s == g) {
        cout << 0;
        return 0;
    }

    bfs(s);

    if (visited[g]) cout << visited[g] - 1;
    else cout << "use the stairs";

    return 0;
}
