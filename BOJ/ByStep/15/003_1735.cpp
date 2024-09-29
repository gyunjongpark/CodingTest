#include<iostream>
using namespace std;

int a, b, c, d;

int getGCD(int a, int b) {
	if (a == 0) return b;
	return getGCD(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c >> d;

	int ja = a * d + b * c;
	int mo = b * d;
	int temp = getGCD(ja, mo);
	
	ja /= temp;
	mo /= temp;

	cout << ja << ' ' << mo;

	return 0;
}
