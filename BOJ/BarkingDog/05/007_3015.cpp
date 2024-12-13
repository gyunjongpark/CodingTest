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

		while (!stk.empty() && stk.top().first <= h) { //입력된 키가 스택의 키보다 크거나 같다면
			ret += stk.top().second; //스택에 있는 사람들을 위에서부터 차례대로 만날 수 있다

			if (stk.top().first == h) { //특별히 스택에서 같은 키를 가진 사람을 만날 때
				cnt += stk.top().second; //입력된 사람과 같은 키인 사람의 수를 포용한다
			}

			stk.pop();
		}

		if (!stk.empty()) { //입력된 키보다 큰 키가 남아있는 경우, 결과 쌍에 1 추가
			ret++;
		}

		stk.push({ h, cnt });
	}

	cout << ret;

	return 0;
}
