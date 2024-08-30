#include<iostream>
#include<stack>
using namespace std;
typedef unsigned long long ll;

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

			while (!stk.empty() && stk.top().first >= h) { //입력된 높이가 현재 저장된 높이보다 작다면 중간 검사
				//현재 저장된 위치부터 역으로 만들 수 있는 직사각형 전부 조사해서 최댓값 갱신
				ret = max(ret, (i - stk.top().second) * stk.top().first);

				idx = stk.top().second; //stk에 저장된 높이들 중에서 h보다 작은 높이 && 최소 인덱스가 되도록 갱신

				stk.pop();
			}

			stk.push({ h,idx }); //현재 h를 최소 높이로 하면서 가로로 가장 긴 직사각형을 계산하기 위해 (h, idx) push
		}

		while (!stk.empty()) { //마지막 기둥에 대하여 검사
			ret = max(ret, (n - stk.top().second) * stk.top().first);

			stk.pop();
		}

		cout << ret<<'\n';
	}

	return 0;
}
