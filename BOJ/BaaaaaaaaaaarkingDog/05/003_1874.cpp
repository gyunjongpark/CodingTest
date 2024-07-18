#include<iostream>
#include<algorithm> //reverse
#include<stack>
#include<vector>
using namespace std;

int n, cnt, arr[100001];
stack<int> stk, ret_stk;
vector<char> result; // '+'와 '-'를 저장할 벡터

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    reverse(arr, arr + n);

    for (int i = 0; i < n; i++) {
        stk.push(arr[i]);
    }

    while (!stk.empty()) {
        // 스택의 top이 현재 cnt보다 작다면 NO 출력
        if (!ret_stk.empty() && stk.top() < ret_stk.top()) {
            cout << "NO" << '\n';
            return 0;
        }

        // 현재 스택의 top이 cnt와 같으면 pop
        if (!ret_stk.empty() && stk.top() == ret_stk.top()) {
            result.push_back('-');
            stk.pop();
            ret_stk.pop();
        }
        else {
            result.push_back('+');
            cnt++;
            ret_stk.push(cnt);
        }
    }

    for (char c : result) {
        cout << c << '\n';
    }

    return 0;
}
