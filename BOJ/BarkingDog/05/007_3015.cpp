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

		int cnt = 1; //본인 포함 같은 키인 사람의 수(초기값은 본인 혼자이므로 항상 1)

		while (!stk.empty() && stk.top().first <= h) { //현재 입력된 키가 이전의 키보다 크거나 같다면
			ret += stk.top().second; //이전 키인 사람의 cnt를 ret에 추가. 이전 사람이 볼 수 있는 사람들은 현재 사람도 볼 수 있다

			if (stk.top().first == h) { //현재 키가 이전 키와 정확히 같다면, 이전 키인 사람의 cnt를 현재 키인 사람의 cnt에 추가
				cnt += stk.top().second;
			}

			stk.pop(); //계산 완료 후 pop
		}

		if (!stk.empty()) { //현재 입력된 키보다 큰 사람이 남아있다면
			ret++; //키 큰 사람 이전의 사람들은 키 큰 사람에 의해서 가려지기 때문에 ret은 무조건 1 추가
		}

		stk.push({ h, cnt }); //(현재 키, 본인 포함 같은 키인 사람의 수)
	}

	cout << ret;

	return 0;
}
