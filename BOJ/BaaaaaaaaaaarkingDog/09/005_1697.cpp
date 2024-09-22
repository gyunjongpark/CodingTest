#include<iostream>
#include<queue>
using namespace std;

int n, k, visited[100001];

void bfs(int n) {
    visited[n] = 1;

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int now = q.front(); q.pop();

        if (now == k) break;

        //방문여부 뿐만 아니라 범위도 함께 체크 필수!
        if (now - 1 >= 0 && !visited[now - 1]) {
            visited[now - 1] = visited[now] + 1;
            q.push(now - 1);
        }

        if (now + 1 <= 100000 && !visited[now + 1]) {
            visited[now + 1] = visited[now] + 1;
            q.push(now + 1);
        }

        if (now * 2 <= 100000 && !visited[now * 2]) {
            visited[now * 2] = visited[now] + 1;
            q.push(now * 2);
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    bfs(n);

    cout << visited[k] - 1;

    return 0;
}
