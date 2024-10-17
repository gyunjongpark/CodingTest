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

		stack<pair<ll, ll>> stk; //init
		ll ret = 0; //init

		for (int i = 0; i < n; i++) {
			cin >> h;

			idx = i;

			while (!stk.empty() && stk.top().first >= h) { //입력된 높이가 현재 높이보다 작거나 같다면 중간 검사
				ret = max(ret, (i - stk.top().second) * stk.top().first); //바로 이전 위치부터 시작해 역으로 만들 수 있는 직사각형 전부 조사

				idx = stk.top().second; //현재까지 나온 높이 중 최저점을 높이로 삼는 가로로 긴 직사각형을 계산하기 위해 가장 작은 높이(stk.top().second)를 idx에 갱신
				stk.pop();
			}

			stk.push({ h,idx });
		}

		while (!stk.empty()) { //마지막 기둥에 대해서 검사
			ret = max(ret, (n - stk.top().second) * stk.top().first);

			stk.pop();
		}

		cout << ret << '\n';
	}

	return 0;
}
