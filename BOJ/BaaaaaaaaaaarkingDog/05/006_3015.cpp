#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;

int n, h;
ll ret;
stack<pair<int, int>> stk;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> h;

		int cnt = 1;

		while (stk.size() && stk.top().first <= h) {
			ret += stk.top().second;

			if (stk.top().first == h) {
				cnt += stk.top().second;
			}

			stk.pop();
		}

		if (stk.size()) {
			ret++;
		}

		stk.push({ h, cnt });
	}

	cout << ret;

	return 0;
}
