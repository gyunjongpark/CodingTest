#include<iostream>
#include<stack>
using namespace std;

int n, temp;
stack<int> stk;
string ret;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    int cnt = 1;

    for (int i = 0; i < n; i++) {
        cin >> temp;
                
        while (cnt <= temp) {
            ret += "+\n";
            stk.push(cnt);
            cnt++;
        }

        //정점을 찍은 후에는 내림차순으로 내려와야 stack으로 입력된 수열을 완성할 수 있다
        if (stk.top() != temp) {
            cout << "NO";

            return 0;
        }

        stk.pop();
        ret += "-\n";
    }
    cout << ret;

    return 0;
}
