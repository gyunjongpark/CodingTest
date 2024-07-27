#include<iostream>
#include<stack>
using namespace std;

int n, ret;
bool flag;
string s;
stack<char> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	for (char c : s) {
		if (stk.empty()) { //비어있다면 무조건 push
			stk.push(c);

			if (c == '(') flag = 1; //레이저 부품 반쪽을 1로 표시
		}
		else { //비어있지 않다면
			if (stk.top() == '(' && c == ')' && flag == 1) { //레이저 완성일 경우
				if (stk.size() > 1) { //레이저 부품 반쪽 '('를 제외하고 막대기가 쌓여있다면
					ret += stk.size() - 1; //'(' 제외하고 쪼개지는 막대기들 추가
				}
				stk.pop(); //레이저 init
				flag = 0; //레이저 init
			}
			else if (stk.top() == '(' && c == ')' && flag == 0) { //상위 막대기가 끊긴 경우
				stk.pop(); //막대기 스택 하나 줄이기
				ret++; //결과는 낱개 막대기 하나 추가
			}
			else {
				stk.push(c);
				if (c == '(') flag = 1;
			}
		}
	}

	cout << ret;

	return 0;
}
