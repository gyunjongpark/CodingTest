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

			if (c == '(') flag = 1; //레이저 부품 반쪽이 들어왔다면 flag = 1
		}
		else {
			if (stk.top() == '(' && c == ')' && flag == 1) { //레이저 완성 시
				ret += stk.size() - 1; //'('를 제외하고 쪼개지는 막대기의 수를 ret에 추가
				
				stk.pop(); //레이저 init
				flag = 0; //레이저 init
			}
			else if (stk.top() == '(' && c == ')' && flag == 0) { //가장 상위의 막대기가 끊어진 경우
				stk.pop(); //막대기의 수 하나 줄이기
				ret++; //상위 막대기의 마지막 부분을 ret에 추가
			}
			else {
				stk.push(c);
				
				if (c == '(') flag = 1; //레이저 부품 반쪽이 들어왔다면 flag = 1
			}
		}
	}
	
	cout << ret;

	return 0;
}
