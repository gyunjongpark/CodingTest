#include<iostream>
using namespace std;
typedef unsigned long long ll;

int a, b, c;

ll go(int a, int b, int c) {
	if (b == 1) return a % c;

	if (b % 2) {
		return (go(a, b / 2, c) * go(a, b / 2, c) % c) * a % c; //홀수 승수인 경우 한번 더 연산
	}
	else {
		return go(a, b / 2, c) * go(a, b / 2, c) % c;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;
	cout << go(a, b, c);

	return 0;
}
