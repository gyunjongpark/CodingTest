#include <iostream>
using namespace std;

const int dy[] = { 0,0,0,-1,1 };  //정면, 동, 서, 북, 남
const int dx[] = { 0,1,-1,0,0 };  //정면, 동, 서, 북, 남
int n, m, y, x, k, a[21][21], dir, temp;
int n1, n2, n3, n4, n5, n6; //주사위의 면

void go(int dir) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
        if (dir == 1) { //동
            temp = n1, n1 = n4, n4 = n6, n6 = n3, n3 = temp;
        }
        else if (dir == 2) { //서
            temp = n1, n1 = n3, n3 = n6, n6 = n4, n4 = temp;
        }
        else if (dir == 3) { //북    
            temp = n1, n1 = n5, n5 = n6, n6 = n2, n2 = temp;
        }
        else if (dir == 4) { //남    
            temp = n1, n1 = n2, n2 = n6, n6 = n5, n5 = temp;
        }

        //아랫면과 주사위 체크
        if (a[ny][nx] == 0) {
            a[ny][nx] = n6; //주사위 -> 아랫면 복사
        }
        else {
            n6 = a[ny][nx]; //아랫면 -> 주사위 복사
            a[ny][nx] = 0; //좌표는 0으로 수정
        }

        //y, x 좌표 바꾸기
        y = ny;
        x = nx;

        //현재 윗면 출력
        cout << n1 << '\n';

        return;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> y >> x >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while (k--) {
        cin >> dir;
        go(dir);
    }

    return 0;
}
