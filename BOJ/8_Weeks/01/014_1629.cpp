#include<iostream>
using namespace std;
typedef long long ll;

int a, b, c;

ll recur(int a, int b, int c) {
	if (b == 1) return a % c;

	if (b % 2) { //홀수 승수인 경우
		return (recur(a, b / 2, c) * recur(a, b / 2, c) % c) * a % c;

		//recur(a, b / 2, c)의 결과는 최대 c - 1이 될 수 있다
		//recur * recur의 결과는 c에 대한 2차방정식이 될 수 있으므로 %c 연산이 필요하다
		
		//홀수 승수인 경우 recur * recur * a
		//a는 최대 c - 1가 될 수 있으므로(c의 차수가 1) %c 연산이 추가로 필요하다	
	}
	else {
		return (recur(a, b / 2, c) * recur(a, b / 2, c) % c);

		//recur(a, b / 2, c)의 결과는 최대 c - 1이 될 수 있다
		//recur * recur의 결과는 c에 대한 2차방정식이 될 수 있으므로 %c 연산이 필요하다
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;
	cout << recur(a, b, c);

	return 0;
}
