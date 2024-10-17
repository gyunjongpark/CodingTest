#include<iostream>
#include<stack>
using namespace std;

stack<char> stk;
string str;
bool flag;
int ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;

	int num = 1; //괄호에 따른 덧셈, 곱셈 계산을 위해 1로 init

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			num *= 2;
			stk.push(str[i]);
		}
		else if (str[i] == '[') {
			num *= 3;
			stk.push(str[i]);
		}
		else if (str[i] == ')') {
			if (stk.empty() || stk.top() != '(') { //짝이 맞지 않는다면 flag = true
				flag = true;
				break;
			}

			if (str[i - 1] == '(') {
				ret += num; //직전 문자와 쌍을 이룬다면 더하기 연산을 진행한다
			}

			stk.pop();
			num /= 2;
		}
		else if (str[i] == ']') {
			if (stk.empty() || stk.top() != '[') {
				flag = 1;
				break;
			}

			if (str[i - 1] == '[') {
				ret += num; //직전 문자와 쌍을 이룬다면 더하기 연산을 진행한다
			}

			stk.pop();
			num /= 3;
		}
	}

	if (!stk.empty()) flag = 1; //double check

	if (flag) cout << 0;
	else cout << ret;

	return 0;
}
