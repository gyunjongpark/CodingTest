#include<iostream>
#include<queue>
#define MAX 61
using namespace std;

int n, a[3], visited[MAX][MAX][MAX]; //최대 체력 60인 SCV를 최대 3기까지 계산하기
int atk[6][3]{ //뮤탈리스크가 공격할 수 있는 경우의 수
    {9,3,1},
    {9,1,3},
    {3,1,9},
    {3,9,1},
    {1,3,9},
    {1,9,3},
};
struct A { //최대 3기이므로 tie 구현은 복잡하다 -> struct
    int a, b, c;
};
queue<A> q;

int bfs(int a, int b, int c) {
    visited[a][b][c] = 1;
    q.push({ a,b,c });

    while (q.size()) {
        int a_q = q.front().a;
        int b_q = q.front().b;
        int c_q = q.front().c;
        q.pop();

        if (visited[0][0][0]) break; //모든 SCV가 죽었다면 break

        for (int i = 0; i < 6; i++) { //모든 공격의 수 계산
            int na = max(0, a_q - atk[i][0]);
            int nb = max(0, b_q - atk[i][1]);
            int nc = max(0, c_q - atk[i][2]);

            if (!visited[na][nb][nc]) {
                visited[na][nb][nc] = visited[a_q][b_q][c_q] + 1;
                q.push({ na,nb,nc }); //visited로 공격 횟수의 최솟값 찾기
            } //방식이 어떻든 레벨별로 visited가 1씩 증가한다
        }
    }

    return visited[0][0][0] - 1; //모로 가도 visited[0][0][0]으로만 가면 된다
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << bfs(a[0], a[1], a[2]); //현재 체력으로 bfs 탐색하기

    return 0;
}
