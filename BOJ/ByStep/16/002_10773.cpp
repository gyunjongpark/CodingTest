#include<iostream>
#include<stack>
using namespace std;

int a, k, ret;
stack<int> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;

	while (k--) {
		cin >> a;

		if (a == 0) {
			if (stk.size()) stk.pop();
			else continue;
		}
		else stk.push(a);
	}

	while (stk.size()) {
		ret += stk.top();
		stk.pop();
	}
	cout << ret;

	return 0;
}
