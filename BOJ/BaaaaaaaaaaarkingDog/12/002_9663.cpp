#include<iostream>
using namespace std;

int n, ret, col[16];

bool check(int level) {
    for (int i = 0; i < level; i++) { //level 이전까지 열들에 대하여
        //같은 행에 queen이 있거나
        //행 차이 = 열 차이일 경우(대각선일 경우) queen을 놓을 수 없다
        //level이 i보다 큰 열이므로 level - i로 연산 진행
        if (col[level] == col[i] || abs(col[level] - col[i]) == level - i) {
            return false;
        }
    }

    return true;
}

void nQueen(int x) { //x열에 queen을 배치하는 경우의 수 계산
    if (x == n) { //n열에 문제없이 도달했다면
        ret++;
        return;
    }

    for (int i = 0; i < n; i++) {
        col[x] = i; //x열 i행에 queen 저장

        if (check(x)) { //x열 i행에 queen을 놓을 수 있는지 check
            nQueen(x + 1); //x열 임의의 행에 queen을 놓았다면 x + 1열 조사(같은 열에서는 queen이 중복되었는지 검사할 필요가 없다)
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    nQueen(0);

    cout << ret;

    return 0;
}
