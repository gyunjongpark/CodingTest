#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, x, ret, a[100004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	cin >> x;

	int l = 0, r = n - 1;

	while (l < r) {
		if (a[l] + a[r] == x) {
			ret++;
			r--;
		}
		else if (a[l] + a[r] < x) l++;
		else if (a[l] + a[r] > x) r--;
	}
	cout << ret;

	return 0;
}
