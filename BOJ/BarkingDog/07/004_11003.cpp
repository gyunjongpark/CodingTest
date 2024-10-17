#include<iostream>
#include<deque>
using namespace std;

int n, l, temp;
deque<pair<int, int>> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        cin >> temp;

        while (dq.size() && dq.back().second >= temp) {
            dq.pop_back(); //구간 내에서 최소값을 찾을 때까지 pop_back
        }

        dq.push_back({ i,temp });

        if (dq.front().first <= i - l) {
            dq.pop_front(); //구간 이동 시 pop_front. i가 l 이상일 경우 매번 갱신
        }
        cout << dq.front().second << ' ';
    }

    return 0;
}
