#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;

stack<int> stk;
int n, height;
ll ret; //n이 8만이므로 최대 64억(서로가 서로를 전부 볼 수 있을 때)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	//monotone stack
	while (n--) {
		cin >> height;

		while (!stk.empty() && stk.top() <= height) {
			stk.pop();
		}

		//본인이 내려다볼 수 있는 빌딩 수의 총합 = 본인을 내려다볼 수 빌딩 수의 총합
		ret += stk.size();

		stk.push(height);
	}

	cout << ret;

	return 0;
}
