#include<iostream>
#include<stack>
using namespace std;

stack<pair<int, int>> stk;
int n, h;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    stk.push({ 100000001,0 }); //init

    cin >> n;

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