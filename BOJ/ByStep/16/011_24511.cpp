#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;
int n, m, x, y;
bool flag[100001]; // 0:queue, 1:stack

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> flag[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (flag[i] == 0) // queue일때만 deque에 원소 삽입
            dq.push_back(x);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> y;
        dq.push_front(y);
        cout << dq.back() << " ";
        dq.pop_back();
    }

    return 0;
}
