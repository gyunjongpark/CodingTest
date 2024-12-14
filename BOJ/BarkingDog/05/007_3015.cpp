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

		int cnt = 1; //입력된 사람과 같은 키인 사람의 수(본인 포함)

		while (!stk.empty() && stk.top().first <= h) { //입력된 키가 크거나 같을 때 점검 시작
			ret += stk.top().second; //스택에 있는 사람들을 top부터 차례대로 만날 수 있다

			if (stk.top().first == h) { //특별히 같은 키를 가진 사람을 만날 때
				cnt += stk.top().second; //현재 키에 대한 cnt에 만난 사람의 cnt를 추가하여 갱신한다
			}

			stk.pop();
		}

		if (!stk.empty()) { //스택에 입력된 키보다 큰 키가 남아있는 경우, 결과 쌍에 1 추가(이전 사람들은 볼 수 없으므로)
			ret++;
		}

		stk.push({ h, cnt });
	}

	cout << ret;

	return 0;
}
