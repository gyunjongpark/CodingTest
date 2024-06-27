#include<iostream>
#include<stack>
#include<string> //getline
using namespace std;

int t;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (getline(cin, s)) {
		if (s == ".") break;
		stack<char> stk; //init

		//분기를 잘 나누자!
		for (char a : s) {
			if (a == '(' || a == ')' || a == '[' || a == ']') {
				if (stk.empty()) stk.push(a);
				else {
					if (stk.top() == '(' && a == ')') stk.pop();
					else if (stk.top() == '[' && a == ']') stk.pop();
					else stk.push(a);
				}
			}
			if (a == '.') stk.push(a);
		}

		if (stk.size() == 1 && stk.top() == '.') cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}
