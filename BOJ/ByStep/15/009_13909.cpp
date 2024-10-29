#include<iostream>
using namespace std;

int n, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i * i <= n; i++) {
		ret++;
	}

	cout << ret;

	return 0;
}
