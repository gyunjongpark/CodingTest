#include<iostream>
#include<cmath>
using namespace std;

int n, m;

bool check(int n) {
	if (n == 1) return 0;
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = n; i <= m; i++) {
		if (check(i)) cout << i << '\n';
	}

	return 0;
}
