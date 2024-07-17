#include<iostream>
using namespace std;

int n, v, cnt, a[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> v;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		if (v > a[i]) cout << a[i] << ' ';
	}

	return 0;
}
