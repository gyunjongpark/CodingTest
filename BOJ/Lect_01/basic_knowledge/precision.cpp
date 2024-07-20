#include<iostream>
using namespace std;

double a = 123.456789;

int main() {
	//반올림은 기본적으로 적용된다

	cout << a << "\n"; // 초기 자릿 수는 6자리로 정해져 있다 -> 123.457

	cout.precision(7); // precision(나타내고 싶은 자리 수) -> 123.4568
	cout << a << "\n"; // 123.4568

	return 0;
}
