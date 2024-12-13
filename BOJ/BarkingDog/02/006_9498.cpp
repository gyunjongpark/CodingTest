#include<iostream>
using namespace std;

int a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a;

	if (a >= 90) cout << 'A';
	else if (a >= 80) cout << 'B';
	else if (a >= 70) cout << 'C';
	else if (a >= 60) cout << 'D';
	else cout << 'F';

	return 0;
}
