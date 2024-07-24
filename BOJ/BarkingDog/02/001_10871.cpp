#include<iostream>
using namespace std;

int n, x, a[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		if (a[i] < x) {
			cout << a[i] << ' ';
		}
	}

	return 0;
}
