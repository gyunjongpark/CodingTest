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

		int cnt = 1; //본인 포함 현재 입력된 사람이 볼 수 있는 사람의 수

		while (!stk.empty() && stk.top().first <= h) { //현재 키가 가장 최근의 큰 키보다 크거나 같다면
			ret += stk.top().second; //최근의 큰 키를 가진 사람이 볼 수 있는 사람들의 수를 결과 쌍에 추가

			if (stk.top().first == h) { //특별히 최근의 큰 키와 현재 키가 정확히 같다면(현재 사람이 포용할 수 있다면)
				cnt += stk.top().second; //최근의 큰 키를 가진 사람이 볼 수 있는 사람들의 수를 현재의 사람이 볼 수 있는 사람 수에 추가
			}

			stk.pop();
		}

		if (!stk.empty()) { //while문을 통과했는데 stk이 비어있지 않은 경우는 현재 키보다 큰 키가 남아있는 경우이므로 결과 쌍에 1 추가
			ret++;
		}

		stk.push({ h, cnt });
	}

	cout << ret;

	return 0;
}
