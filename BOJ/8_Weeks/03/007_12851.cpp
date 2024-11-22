#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, k, visited[200004];
int cnt[200004];

void bfs(int n) {
    visited[n] = 1; //방문 여부
    cnt[n] = 1; //방문 횟수

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (cur == k) break;

        for (int next : {cur - 1, cur + 1, cur * 2}) {
            if (0 <= next && next <= 100000) {            
                if (!visited[next]) {
                    visited[next] = visited[cur] + 1;
                    q.push(next);

                    cnt[next] = cnt[cur]; //방문 횟수 복사하기
                }
                else if (visited[next] == visited[cur] + 1) { //최단 거리로 도달한 경우
                    cnt[next] += cnt[cur]; //최단 거리로 방문한 횟수를 추가로 얹어서 갱신
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
