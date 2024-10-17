#include<iostream>
#include<stack>
using namespace std;

stack<pair<int, int>> stk;
int n, h;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	stk.push({ 100000001,0 }); //0번째 탑 init

	for (int i = 1; i <= n; i++) {
		cin >> h;

		while (!stk.empty() && stk.top().first <= h) {
			stk.pop();
		}

		cout << stk.top().second << ' ';

		stk.push({ h,i });
	}

	return 0;
}
