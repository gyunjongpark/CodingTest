#include<iostream>
#include<stack>
using namespace std;

int n, c, x;
stack<int> stk;

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
			if (!stk.empty()) {
				cout << stk.top() << '\n';
				stk.pop();
			}
			else cout << -1 << '\n';
		}
		else if (c == 3) {
			cout << stk.size() << '\n';
		}
		else if (c == 4) {
			if (!stk.empty()) cout << 0 << '\n';
			else cout << 1 << '\n';
		}
		else if (c == 5) {
			if (!stk.empty()) cout << stk.top() << '\n';
			else cout << -1 << '\n';
		}
	}

	return 0;
}
