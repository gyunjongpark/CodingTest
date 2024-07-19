#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;

stack<int> stk;
ll ret;
int n, h;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    //monotone stack 방법
    while(n--){
        cin >> h;
        
        while (!stk.empty() && h >= stk.top()) {
            stk.pop();
        }
        ret += stk.size(); //본인을 내려다 볼 수 있는 경우의 수 합산

        stk.push(h);
    }
    cout << ret;

    return 0;
}
