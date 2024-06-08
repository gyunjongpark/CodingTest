#include<iostream>
#include<algorithm>
#define MAX 51
using namespace std;

int n, a[MAX], cnt;

int gcd(int a, int b) {
	if (a == 0) return b;

	return gcd(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	for (int i = 0; i < n - 1; i++) {
		if (gcd(a[i], a[i + 1]) == 1) continue;

		for (int j = a[i] + 1; j < a[i + 1]; j++) {
			if (gcd(a[i], j) == 1) {
				if (gcd(a[i + 1], j) == 1) {
					cnt++;
					break;
				}
			}

			//마지막 요소 접근 시 +2
			if (j == a[i + 1] - 1) {
				cnt += 2;
				break;
			}
		}
	}
	cout << cnt;

	return 0;
}
