#include<iostream>
using namespace std;

int n, ret, col[16];

bool check(int level) {
    for (int i = 0; i < level; i++) { //level 이전까지 행들에 대하여
        //같은 열에 queen이 있거나
        //행 차이와 열 차이가 같을 경우(대각선) queen을 놓을 수 없다
        //level이 반복되는 i보다 무조건 큰 행이므로 level - i로 연산 진행
        if (col[level] == col[i] || (level - i) == abs(col[level] - col[i])) {
            return false;
        }
    }

    return true;
}

void nQueen(int x) { //x행에 queen을 배치하는 경우의 수 계산
    if (x == n) { //x가 n까지 문제없이 도달했다면
        ret++;

        return;
    }

    for (int i = 0; i < n; i++) {
        col[x] = i; //x행 i열에 queen 저장

        if (check(x)) { //x행에 queen을 놓을 수 있는지 check
            nQueen(x + 1); //x행 임의의 열에 queen을 놓았다면 x + 1행으로 바로 넘어간다(같은 행에서 queen은 중복될 수 없다)
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
