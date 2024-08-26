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

        //최소 시간을 구하기 위해 작은 가중치부터 우선적으로 push
        if (now * 2 <= 100000 && !visited[now * 2]) {
            visited[now * 2] = visited[now];
            q.push(now * 2);
        }

        if (now - 1 >= 0 && !visited[now - 1]) {
            visited[now - 1] = visited[now] + 1;
            q.push(now - 1);
        }

        if (now + 1 <= 100000 && !visited[now + 1]) {
            visited[now + 1] = visited[now] + 1;
            q.push(now + 1);
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
