#include<iostream>
#include<algorithm>
#define MAX 54
using namespace std;

int n, cnt, a[MAX];

int getGCD(int a, int b) {
	if (a == 0) return b;

	return getGCD(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	for (int i = 0; i < n - 1; i++) { //a[0] ~ a[49]
		if (getGCD(a[i], a[i + 1]) == 1) continue;

		for (int j = a[i] + 1; j < a[i + 1]; j++) {
			if (getGCD(a[i], j) == 1) {
				if (getGCD(a[i + 1], j) == 1) {
					cnt++; //1개의 수로 공약수열 완성
					break;
				}
			}

			//마지막 요소 접근 시 2개의 수 추가(1개의 수로는 공약수열 완성 불가)
			if (j == a[i + 1] - 1) {
				cnt += 2;
				break;
			}
		}
	}
	cout << cnt;

	return 0;
}
