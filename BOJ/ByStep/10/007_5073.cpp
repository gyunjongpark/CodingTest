#include<iostream>
using namespace std;

int a, b, c, maxLine;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> a >> b >> c;
		maxLine = max(max(a, b), c);

		if (a == 0 && b == 0 && c == 0) break;
		
		if (a + b + c - maxLine <= maxLine) cout << "Invalid\n";
		else if (a == b && b == c) cout << "Equilateral\n";
		else if (a == b || a == c || b == c) cout << "Isosceles\n";
		else cout << "Scalene\n";
	}

	return 0;
}
