#include<iostream>
using namespace std;

int n, l, a[101][101], b[101][101], ret;

void go(int a[101][101]) {
    for (int i = 0; i < n; i++) {
        int cnt = 1; //현재 본인과 같은 높이의 블록의 수
        int j; //12100.2048(Easy)에서 c 테크닉과 비슷하다
        
        for (j = 0; j < n - 1; j++) {
            if (a[i][j] == a[i][j + 1]) cnt++; //본인과 같은 높이의 블록의 수 증가
            else if (a[i][j] == a[i][j + 1] - 1 && cnt >= l) cnt = 1; //높아진 블록에서 새 출발
            else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1; //l을 온전히 품을 때까지 cnt 조정
            
            //올라가는 경사로의 길이만큼의 cnt가 쌓여있지 않았거나 (두 번째 if 문)
            //내려가는 경사로의 길이만큼의 블록이 이어지지 않아 cnt가 음수가 된다면 (세 번째 if 문)
            else break;
        }

        //마지막 블록에서 내려가는 경사로를 온전히 품어야하므로 cnt >= 0 조건 추가
        if (j == n - 1 && cnt >= 0) ret++;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[j][i] = a[i][j]; //입력 좌표를 그대로 뒤집는 방법
        }
    }

    go(a);
    go(b);

    cout << ret;
    
    return 0;
}
