#include<iostream>
using namespace std;

int n, l, a[101][101], b[101][101], ret;

void go(int a[101][101]) {
    for (int i = 0; i < n; i++) {
        int cnt = 1; //현재 본인과 같은 높이의 블록의 수
        int j;

        for (j = 0; j < n - 1; j++) {
            if (a[i][j] == a[i][j + 1]) cnt++; //본인과 같은 높이의 블록의 수 증가
            else if (a[i][j] == a[i][j + 1] - 1 && cnt >= l) cnt = 1; //높아진 블록에서 새출발
            else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1; //l을 온전히 품을 때까지 cnt 조정
            
            //올라가는 경사로의 길이만큼의 cnt가 없거나 (두 번째 if 문)
            //내려가는 경사로가 깔릴만큼의 배열의 길이가 없어 cnt = 0이 안된다면 (세 번째 if 문)
            else break;
        }

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
            b[j][i] = a[i][j];
        }
    }

    go(a);
    go(b);

    cout << ret;
    

    return 0;
}