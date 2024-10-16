#include<iostream>
using namespace std;

int n, a[1000001], cnt[2000001], x, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cin >> x;

	for (int i = 1; i <= n; i++) {
		if (x > a[i] && cnt[x - a[i]]) ret++;

		cnt[a[i]] = 1;
	}

	cout << ret;

	return 0;
}
