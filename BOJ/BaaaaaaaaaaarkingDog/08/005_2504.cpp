#include<iostream>
#include<stack>
using namespace std;

stack<char> stk;
string str;
int sum = 0; //누적해서 더해질 값
int num = 1; //곱해질 값
bool flag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;

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
			if (stk.empty() || stk.top() != '(') { //어떤 연산을 하든 닫혀야 한다
				flag = 1;
				break;
			}

			if (str[i - 1] == '(') { //누적값의 갱신은 직전 문자와 쌍을 이루어야 한다
				sum += num;
			}

			//if문을 통과했다면 반드시 stk.top()=='('이다
			stk.pop();
			num /= 2;
		}
		else if (str[i] == ']') {
			if (stk.empty() || stk.top() != '[') {
				flag = 1;
				break;
			}

			if (str[i - 1] == '[') {
				sum += num;
			}

			//if문을 통과했다면 반드시 stk.top()=='['이다
			stk.pop();
			num /= 3;
		}
	}

	if (!stk.empty()) flag = 1; //double check

	if (flag) cout << 0;
	else cout << sum;

	return 0;
}
