#include<iostream>
#include<algorithm> //reverse
using namespace std;

int a, b;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> a >> b;

	while (a > 1) {
		int temp = a % b;

		if (10 <= temp && temp <= 35) s += (char)(temp + 55);
		else s += (char)(temp + 48);

		a /= b;
	}

	if (a == 1) s += '1';

	reverse(s.begin(), s.end());

	cout << s;

	return 0;
}
