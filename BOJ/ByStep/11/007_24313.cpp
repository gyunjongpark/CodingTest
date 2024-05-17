#include<iostream>
using namespace std;

int a1, a0, c, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a1 >> a0;
	cin >> c >> n;

	if ((a1 * n + a0 <= c * n) && a1 <= c) cout << 1;
	else cout << 0;

	return 0;
}
