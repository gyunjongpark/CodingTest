#include<iostream>
#include<stack>
using namespace std;

int n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> s;

		stack<char> stk;

		for (char a : s) {
			if (stk.size()) {
				if (stk.top() == '(' && a == ')') stk.pop();
				else stk.push(a);
			}
			else { // stk에 쌓인 것이 없다면 무조건 push
				stk.push(a);
			}
		}

		if (stk.size()) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}

	return 0;
}
