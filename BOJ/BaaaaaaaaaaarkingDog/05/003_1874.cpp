#include<iostream>
#include<stack>
#include<vector>
#include<algorithm> //reverse
using namespace std;

int n, arr[100001];
stack<int> stk, ret_stk;
vector<char> ret;

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
    
    int cnt = 1;
    while (!stk.empty()) {
        if (ret_stk.empty()) { // 비어있을 경우 무조건 채운다
            ret.push_back('+');
            ret_stk.push(cnt);
            cnt++;
        }

        if (!ret_stk.empty()) { 
            if (stk.top() < ret_stk.top()) { // 순서가 불가능한 경우
                cout << "NO" << '\n';
                return 0;
            }

            if (stk.top() == ret_stk.top()) { // 값이 같으면 소거
                ret.push_back('-');
                stk.pop();
                ret_stk.pop();
            }
            else { // 같지 않은 경우 stack 채우기
                ret.push_back('+');
                ret_stk.push(cnt);
                cnt++;
            }
        }
    }
    for (char c : ret) cout << c << '\n';

    return 0;
}
