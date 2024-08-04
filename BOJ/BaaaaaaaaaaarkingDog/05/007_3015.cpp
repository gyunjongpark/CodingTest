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
		cin >> h; //현재 키 입력

		int cnt = 1; //본인 포함 같은 키인 사람의 수(초기값은 본인 혼자이므로 1)

		while (stk.size() && stk.top().first <= h) { //현재 키가 이전의 값들보다 클 때
			ret += stk.top().second; //현재 키로 볼 수 있는 사람(들)의 수를 ret에 추가

			if (stk.top().first == h) { //현재 키가 이전 키와 같다면 이전까지 같은 키의 사람(들)을 더해서 cnt 갱신
				cnt += stk.top().second;
			}

			stk.pop(); //계산 완료 후 pop
		}

		if (stk.size()) { //현재 키보다 큰 사람이 남아있다면
			ret++; //키 큰 사람 기준으로도 과거에 이미 pop 연산을 진행했기 때문에 남은 사람은 무조건 1명이다. 따라서 1 추가
		}

		stk.push({ h, cnt });
	}

	cout << ret;

	return 0;
}
