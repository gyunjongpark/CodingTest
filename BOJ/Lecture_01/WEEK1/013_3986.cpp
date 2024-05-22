#include<iostream>
#include<stack>
using namespace std;

int n, ret;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;

		stack<char> stk;
		for (char c : s) {
			if (stk.size() && c == stk.top()) stk.pop();
			else stk.push(c);
		}
		if (stk.empty()) ret++;
	}

	cout << ret;

	return 0;
}
