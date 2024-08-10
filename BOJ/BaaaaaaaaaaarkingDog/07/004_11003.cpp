#include<iostream>
#include<deque>
using namespace std;

int n, L, temp;
deque<pair<int, int>> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> L;

    for (int i = 0; i < n; i++) {
        cin >> temp;

        while (dq.size() && dq.back().second >= temp) {
            dq.pop_back(); //구간마다 최솟값이 아닌 수는 바로 pop_back
        }

        dq.push_back({ i,temp });

        if (dq.front().first <= i - L) {
            
            //구간의 시작점을 맞추기 위한 pop_front
            dq.pop_front(); //i가 L 이상일 경우 매번 갱신
        }

        cout << dq.front().second << ' ';
    }

    return 0;
}
