#include<iostream>
#include<stack>
using namespace std;

string s;
stack<char> stk;
int ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.push(s[i]);
        }

        if (s[i] == ')') {
            stk.pop();

            if (s[i - 1] == '(') { //레이저였다면
                ret += stk.size();
            }
            else {
                ret++;
            }
        }
    }

	cout << ret;

	return 0;
}
