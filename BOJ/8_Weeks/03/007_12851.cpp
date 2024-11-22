#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, k, visited[200004];
int cnt[200004];

void bfs(int n) {
    visited[n] = 1;
    cnt[n] = 1;

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int now = q.front(); q.pop();

        if (now == k) break;

        for (int next : {now - 1, now + 1, now * 2}) {
            if (next >= 0 && next <= 100000) { //범위 체크                
                if (!visited[next]) { //처음 방문하는 경우
                    visited[next] = visited[now] + 1;
                    q.push(next);
                    cnt[next] = cnt[now]; //경로 초기화
                }
                else if (visited[next] == visited[now] + 1) { //최단 거리로 도달한 경우
                    cnt[next] += cnt[now];
                }
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    bfs(n);

    cout << visited[k] - 1 << '\n' << cnt[k];

    return 0;
}
