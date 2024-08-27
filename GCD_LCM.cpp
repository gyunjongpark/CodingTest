#include<iostream>
using namespace std;

int a, b;

int getGCD(int a, int b) {
	if (a == 0) return b;
	
	return getGCD(b % a, a);
}

int getLCM(int a, int b) {
	return (a * b) / getGCD(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	cout << getGCD(a, b);
	cout << getLCM(a, b);

	return 0;
}
