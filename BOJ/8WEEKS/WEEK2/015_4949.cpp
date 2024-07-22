#include<iostream>
#include<stack>
#include<string> //getline
using namespace std;

string s;
int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (getline(cin, s)) {
		if (s == ".") break;

		stack<char> stk; // init

		for (char a : s) {
			if (a == '(' || a == ')' || a == '[' || a == ']') { // 4가지 반 괄호에 대해서만 생각
				if (stk.empty()) { // stk이 비어있다면 무조건 push
					stk.push(a);
				}
				else {
					if (stk.top() == '(' && a == ')') stk.pop();
					else if (stk.top() == '[' && a == ']') stk.pop();
					else stk.push(a);
				}
			}
			if (a == '.') stk.push(a);
		}

		if (stk.size() == 1 && stk.top() == '.') { // .만 남아있다면
			cout << "yes"<<'\n';
		}
		else cout << "no"<<'\n';
	}

	return 0;
}
