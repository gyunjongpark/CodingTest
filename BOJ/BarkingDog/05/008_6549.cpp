#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;

int n, h, idx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> n;

		if (n == 0) break;

		ll ret = 0; //가장 넓이가 큰 직사각형의 넓이
		stack<pair<ll, ll>> stk; //높이와 인덱스를 pair로 저장

		for (int i = 0; i < n; i++) {
			cin >> h;

			idx = i;

			while (!stk.empty() && stk.top().first >= h) { //스택보다 낮은 높이의 직사각형 입력 시 중간 점검
				ret = max(ret, (i - stk.top().second) * stk.top().first); //이전 인덱스까지 중 최대 넓이를 계산

				idx = stk.top().second; //인덱스는 현재 stk.top().first 높이를 품을 수 있는 최대한의 지점으로 변경
				stk.pop();
			}

			stk.push({ h,idx });
		}

		while (!stk.empty()) { //마지막 직사각형에 대해 최종 점검
			ret = max(ret, (n - stk.top().second) * stk.top().first);

			stk.pop();
		}

		cout << ret << '\n';
	}

	return 0;
}
