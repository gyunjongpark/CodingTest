#include<iostream>
#include<stack>
using namespace std;

stack<int> stk;
int n, a[1000001], ret[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	fill(ret, ret + n, -1); // init

	for (int i = 0; i < n; i++) {

		// stack은 갱신할 때마다 size check 필수
		while (stk.size() && a[stk.top()] < a[i]) {
			ret[stk.top()] = a[i];
			stk.pop();
		}
		stk.push(i);
	}

	// n-1까지만 출력
	for (int i = 0; i < n; i++) {
		cout << ret[i] << ' ';
	}

	return 0;
}
