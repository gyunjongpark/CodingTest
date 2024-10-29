#include<iostream>
using namespace std;

int n, dot = 2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;

	while (n--) {
		dot = dot * 2 - 1;
	}

	cout << dot * dot;

	return 0;
}
