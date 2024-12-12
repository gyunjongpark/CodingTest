#include<iostream>
#include<stack>
using namespace std;

int n, temp;
stack<int> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int cnt = 1;

	for (int i = 0; i < n; i++) {
		cin >> temp;

		stk.push(temp);

		while (!stk.empty() && stk.top() == cnt) {
			stk.pop();
			cnt++;
		}
	}

	if (stk.empty()) cout << "Nice";
	else cout << "Sad";

	return 0;
}
