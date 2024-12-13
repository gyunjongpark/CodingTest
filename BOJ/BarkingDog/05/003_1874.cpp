#include<iostream>
#include<stack>
using namespace std;

stack<int> stk;
string ret;
int n, temp;
int cnt = 1; //부호 출력을 위한 cnt
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
			flag = true; //도중에 스택 수열이 성립되지 않아도 입력받는다
		}
		else {
			ret += "-\n";
			stk.pop();
		}
	}

	if (flag) {
		cout << "NO";
	}
	else {
		cout << ret;
	}

	return 0;
}
