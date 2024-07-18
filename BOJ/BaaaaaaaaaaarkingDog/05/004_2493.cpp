#include<iostream>
#include<stack>
using namespace std;

stack<pair<int, int>> stk;
int n, h;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    stk.push({ 100000001, 0 });

    for (int i = 1; i <= n; i++) {
        cin >> h;

        while (h > stk.top().first) {
            stk.pop();
        }

        cout << stk.top().second << ' ';

        stk.push({ h,i });
    }

    return 0;
}

//뭔가 이전 값이 필요한 경우, 과거 값이 걸리는 경우에는 stack, 누적합 생각
