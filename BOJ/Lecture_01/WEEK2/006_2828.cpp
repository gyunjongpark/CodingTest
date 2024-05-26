#include<iostream>
using namespace std;

int n, m, j, k, cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> j;

	int left = 1, right = left + m - 1;

	while (j--) {
		cin >> k;
		if (left <= k && k <= right) continue;
		else {
			if (k < left) {
				cnt += left - k;
				left = k;
				right = left + m - 1;
			}
			else if (right < k) {
				cnt += k - right;
				right = k;
				left = right - m + 1;
			}
		}
	}

	cout << cnt;

	return 0;
}
