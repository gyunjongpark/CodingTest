#include<iostream>
#include<stack>
using namespace std;

stack<int> stk;
string ret;
int n, temp;
bool flag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int cnt = 1; //부호 출력을 위한 cnt 변수
	
	while (n--) {
		cin >> temp;

		while (cnt <= temp) {
			ret += "+\n";
			stk.push(cnt);
			cnt++;
		}

		if (stk.top() != temp) {
			flag = 1; //스택 수열이 성립되지 않아도 일단은 모두 입력받는다
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
