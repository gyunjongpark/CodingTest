#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;

stack<int> stk;
int n, height;
ll ret; //최악의 경우 n=8만, (n * n - 1) / 2 -> 64억

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

		ret += stk.size(); //오른쪽 방향으로 본인을 내려다 볼 수 있는 경우의 수 합산

		stk.push(height);
	}

	cout << ret;

	return 0;
}
