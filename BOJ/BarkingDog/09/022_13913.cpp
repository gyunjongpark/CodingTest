#include<iostream>
#include<queue>
#include<deque>
using namespace std;

int n, k, visited[100001], pre[100001];

void bfs(int n) {
    visited[n] = 1;

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int now = q.front(); q.pop();

        if (now == k) break;

        if (now - 1 >= 0 && !visited[now - 1]) {
            visited[now - 1] = visited[now] + 1;
            q.push(now - 1);

            pre[now - 1] = now;
        }

        if (now + 1 <= 100000 && !visited[now + 1]) {
            visited[now + 1] = visited[now] + 1;
            q.push(now + 1);

            pre[now + 1] = now;
        }

        if (now * 2 <= 100000 && !visited[now * 2]) {
            visited[now * 2] = visited[now] + 1;
            q.push(now * 2);

            pre[now * 2] = now;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    bfs(n);

    cout << visited[k] - 1 << '\n';

    deque<int> track = { k };

    while (track.front() != n) {
        track.push_front(pre[track.front()]);
    }

    for (int i : track) cout << i << ' ';

    return 0;
}
