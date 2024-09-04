#include <iostream>
using namespace std;

int t, m, n, x, y;

int find_kaylee_year(int M, int N, int x, int y) {
    int year = x;  //<x, y>가 나타나는 연도를 찾기 위해 x부터 시작
    int current_y = (x % N == 0) ? N : (x % N);  //y값 초기화

    while (year <= M * N) {  //최대 연도는 M * N
        if (current_y == y) {  //현재 y가 주어진 y와 같으면, year 반환
            return year;
        }
        year += M;  //x가 다음 나타나는 year로 이동
        current_y = (current_y + M) % N;  //y값 갱신
        if (current_y == 0) current_y = N;
    }

    return -1;  //<x, y>가 존재하지 않으면 -1 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> m >> n >> x >> y;
        cout << find_kaylee_year(m, n, x, y) << '\n';
    }

    return 0;
}
