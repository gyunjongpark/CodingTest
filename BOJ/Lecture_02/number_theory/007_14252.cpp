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

			//해당 수가 조건 만족 시 1개의 수 추가 후 반환
			if (cnt > 1) { 
				ret++;
				break;
			}

			//범위의 마지막 요소까지 접근 시 2개의 수 추가
			if (j == a[i + 1] - 1) {
				ret += 2;
			}
		}
	}
	cout << ret;

	return 0;
}
