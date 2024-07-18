#include<iostream>
#include<stack>
using namespace std;

const int MX = 1000005;
int dat[MX], pos;

void push(int x) {
	dat[pos++] = x;
}

void pop() {
	pos--;
}

int top() {
	return dat[pos - 1];
}

void test() {
	push(5); push(4); push(3);

	cout << top() << '\n'; // 3

	pop(); pop();

	cout << top() << '\n'; // 5

	push(10); push(12);

	cout << top() << '\n'; // 12

	pop();

	cout << top() << '\n'; // 10

	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	test();

	return 0;
}
