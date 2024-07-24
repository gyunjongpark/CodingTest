#include<iostream>
#include<stack>
using namespace std;

stack<int> stk;
int n, c, x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> c;
		
		if (c == 1) {
			cin >> x;
			stk.push(x);
		}
		else if (c == 2) {
			if (stk.size()) {
				cout << stk.top() << '\n';
				stk.pop();
			}
			else cout << -1 << '\n';
		}
		else if (c == 3) {
			cout << stk.size() << '\n';
		}
		else if (c == 4) {
			if (stk.size()) cout << 0 << '\n';
			else cout << 1 << '\n';
		}
		else if (c == 5) {
			if (stk.size()) cout << stk.top() << '\n';
			else cout << -1 << '\n';
		}
	}

	return 0;
}
