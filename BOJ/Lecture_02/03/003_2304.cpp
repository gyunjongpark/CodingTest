#include<iostream>
#define MAX 1004
using namespace std;

int n, x, y, a[MAX], s[MAX];
int maxPos, maxVal;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) { //a[1] ~ a[1000]
		cin >> x >> y;
		a[x] = y; //높이 저장

		if (y >= maxVal) { //가장 우측의 최대값을 maxPos, maxVal로 저장한다
			maxPos = x;
			maxVal = y;
		}
	}

	//왼쪽부터 maxPos 직전까지 검사, a[1]은 비교 대상 없이 그대로
	for (int i = 2; i < maxPos; i++) {
		if (a[i - 1] >= a[i]) {
			a[i] = a[i - 1];
		}
	}

	//오른쪽부터 maxPos 직전까지 검사, a[1000]은 비교 대상 없이 그대로
	for (int i = 999; i > maxPos; i--) {
		if (a[i + 1] >= a[i]) {
			a[i] = a[i + 1];
		}
	}

	for (int i = 1; i <= 1000; i++) {
		s[i] = s[i - 1] + a[i];
	}
	cout << s[1000];

	return 0;
}
