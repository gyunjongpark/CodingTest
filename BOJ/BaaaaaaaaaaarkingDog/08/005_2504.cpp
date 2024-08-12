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

	int num = 1; //괄호의 값 계산을 위한 num

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
			if (stk.empty() || stk.top() != '(') {
				flag = 1;
				break;
			}

			//if문을 통과했다면 반드시 stk.top()=='('이다

			if (str[i - 1] == '(') { //직전 문자와 쌍을 이룬다면
				ret += num;
			}

			stk.pop(); //원상 복구
			num /= 2; //원상 복구
		}
		else if (str[i] == ']') {
			if (stk.empty() || stk.top() != '[') {
				flag = 1;
				break;
			}

			//if문을 통과했다면 반드시 stk.top()=='['이다

			if (str[i - 1] == '[') { //직전 문자와 쌍을 이룬다면
				ret += num;
			}

			stk.pop(); //원상 복구
			num /= 3; //원상 복구
		}
	}

	if (!stk.empty()) flag = 1; //double check

	if (flag) cout << 0;
	else cout << ret;

	return 0;
}
