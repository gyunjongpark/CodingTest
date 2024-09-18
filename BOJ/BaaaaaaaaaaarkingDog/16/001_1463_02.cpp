#include<iostream>
#include<queue>
using namespace std;

int k, visited[1000001];

void bfs(int n) { //using bfs method
    visited[n] = 1;

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int now = q.front(); q.pop();

        if (now == k) break;

        if (now * 3 <= 1000000 && !visited[now * 3]) {
            visited[now * 3] = visited[now] + 1;
            q.push(now * 3);
        }
        if (now * 2 <= 1000000 && !visited[now * 2]) {
            visited[now * 2] = visited[now] + 1;
            q.push(now * 2);
        }
        if (now + 1 <= 1000000 && !visited[now + 1]) {
            visited[now + 1] = visited[now] + 1;
            q.push(now + 1);
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;

    bfs(1);

    cout << visited[k] - 1;

    return 0;
}
