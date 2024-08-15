#include<iostream>
#include<stack>
using namespace std;
typedef unsigned long long ll;

int n, h, idx; //init

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> n;

		if (n == 0) break;

		stack<pair<ll, ll>> stk; //init
		ll ret = 0; //init

		for (int i = 0; i < n; i++) {
			cin >> h;

			idx = i;

			while (!stk.empty() && stk.top().first >= h) { //직전 히스토그램까지 중에서 역순으로 넓이 조사
				ret = max(ret, (i - stk.top().second) * stk.top().first);

				idx = stk.top().second;

				stk.pop();
			}

			stk.push({ h,idx });
		}

		while (!stk.empty()) { //마지막 기둥에 대하여 계산
			ret = max(ret, (n - stk.top().second) * stk.top().first);

			stk.pop();
		}

		cout << ret << '\n';
	}

	return 0;
}
