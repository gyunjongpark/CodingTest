#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;

stack<int> stk;
int n, height;
ll ret; //최악의 경우 n = 8만, (n * n - 1) / 2 -> 64억

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	//monotone stack
	while(n--) {
		cin >> height;

		while (!stk.empty() && stk.top() <= height) {
			stk.pop();
		}

		//본인이 내려다볼 수 있는 빌딩 수의 합 = 본인을 내려다보는 빌딩 수의 합
		ret += stk.size(); //오른쪽 방향으로 본인을 내려다 보는 빌딩의 수 합산

		stk.push(height);
	}

	cout << ret;

	return 0;
}
