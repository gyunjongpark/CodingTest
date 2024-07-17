#include<iostream>
using namespace std;

int n, y, m, temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		y += (1 + (temp / 30)) * 10;
		m += (1 + (temp / 60)) * 15;
	}
	if (y > m) {
		cout << "M " << m;
	}
	else if (y < m) {
		cout << "Y " << y;
	}
	else {
		cout << "Y M " << y;
	}

	return 0;
}
