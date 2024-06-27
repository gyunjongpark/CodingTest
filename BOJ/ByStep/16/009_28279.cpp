#include<iostream>
#include<deque>
using namespace std;

deque<int> dq;
int t, n, a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n;

		if (n == 1) {
			cin >> a;
			dq.push_front(a);
		}
		else if (n == 2) {
			cin >> a;
			dq.push_back(a);
		}
		else if (n == 3) {
			if (dq.size()) {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else cout << -1 << '\n';
		}
		else if (n == 4) {
			if (dq.size()) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else cout << -1 << '\n';
		}
		else if (n == 5) {
			cout << dq.size() << '\n';
		}
		else if (n == 6) {
			if (dq.size()) cout << 0 << '\n';
			else cout << 1 << '\n';
		}
		else if (n == 7) {
			if (dq.size()) {
				cout << dq.front() << '\n';
			}
			else cout << -1 << '\n';
		}
		else if (n == 8) {
			if (dq.size()) {
				cout << dq.back() << '\n';
			}
			else cout << -1 << '\n';
		}
	}

	return 0;
}
