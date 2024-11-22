#include<iostream>
#include<queue>
#include<vector>
#include<algorithm> //reverse
using namespace std;

int n, k, visited[100001];
int pre[100001];
vector<int> ret;

void bfs(int n) {
    visited[n] = 1; //방문 여부

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

                    pre[next] = cur;
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

    cout << visited[k] - 1 << '\n';

    int cur = k;

    while (true) { //cur가 출발점 n에 도달할 때까지
        if (cur == n) break;
        
        ret.push_back(cur); //현재 노드 추가
        cur = pre[cur];     //이전 노드로 이동
    }

    ret.push_back(n); //마지막 이전 노드 추가(첫 노드)
    reverse(ret.begin(), ret.end()); //역순으로 정렬

    for (int i : ret) cout << i << ' '; //경로 출력

    return 0;
}
