#include<iostream>
#include<stack>
using namespace std;

int cnt = 1, n, t;
stack<int> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> t;

		if (t == cnt) cnt++;
		else stk.push(t);

		while (stk.size()) {
			if (stk.top() == cnt) {
				stk.pop();
				cnt++;
			}
			else break;
		}
  }
  
	if (stk.size()) cout << "Sad";
	else cout << "Nice";

	return 0;
}
