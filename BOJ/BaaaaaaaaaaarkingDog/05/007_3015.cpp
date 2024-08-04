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

		int cnt = 1; //본인 포함 같은 키인 사람의 수(초기값은 본인 혼자이므로 1)

		while (stk.size() && stk.top().first <= h) { //현재 키가 이전보다 같거나 크다면
			ret += stk.top().second; //현재 키로 볼 수 있는 사람의 수 ret에 추가

			if (stk.top().first == h) { //현재 키가 이전 키와 같다면 이전까지 같은 키의 사람을 더해서 cnt 갱신
				cnt += stk.top().second;
			}

			stk.pop(); //현재 키보다 작은 사람들은 더 이상 계산에 쓰이지 않는다
		}

		if (stk.size()) { //현재 키보다 큰 사람이 있다면(키 큰 사람 이전은 pop 연산으로 이미 삭제되었기 때문에 유일하다. 따라서 1 추가)
			ret++;
		}

		stk.push({ h, cnt });
	}

	cout << ret;

	return 0;
}
