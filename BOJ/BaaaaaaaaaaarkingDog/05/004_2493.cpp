#include<iostream>
#include<stack>
using namespace std;

stack<pair<int, int>> stk;
int n, h;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    stk.push({ 100000001,0 }); //수신 받는 탑이 존재하지 않는 경우 0 반환

    for (int i = 1; i <= n; i++) { //1부터 시작
        cin >> h;

        while (stk.size() && stk.top().first < h) {
            stk.pop();
        }

        cout << stk.top().second << ' ';

        stk.push({ h,i });
    }

    return 0;
}
