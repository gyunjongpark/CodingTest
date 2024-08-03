#include<iostream>
#include<stack>
using namespace std;

stack<int> stk;
string ret;
int n, temp;
int cnt = 1;
bool flag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> temp;

		while (cnt <= temp) {
			ret += "+\n";
			stk.push(cnt);
			cnt++;
		}

		if (stk.top() != temp) {
			flag = 1; //스택 수열이 아니어도 일단은 전부 입력받는다
		}

		if (stk.top() == temp) {
			ret += "-\n";
			stk.pop();
		}
	}

	if (flag) cout << "NO";
	else cout << ret;

	return 0;
}
