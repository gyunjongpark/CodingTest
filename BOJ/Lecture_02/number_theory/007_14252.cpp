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

	int ret = 0;
	for (int i = 0; i < n - 1; i++) {
		if (gcd(a[i], a[i + 1]) == 1) continue;

		for (int j = a[i] + 1; j < a[i + 1]; j++) {
			int cnt = 0;
			if (gcd(a[i], j) == 1) cnt++;
			if (gcd(j, a[i + 1]) == 1) cnt++;

			//j 하나만 삽입해도 조건 만족. +1
			if (cnt > 1) { 
				ret++;
				break;
			}

			//범위의 마지막 요소까지 접근 시 2개 추가. +2
			if (j == a[i + 1] - 1) {
				ret += 2;
				break;
			}
		}
	}
	cout << ret;

	return 0;
}
