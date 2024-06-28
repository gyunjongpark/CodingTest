#include<iostream>
#define MAX 1004
using namespace std;

int n, x, y, a[MAX], s[MAX];
int maxPos, maxVal;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	//가장 우축의 최대값을 저장한다
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		a[x] = y;
		if (y >= maxVal) {
			maxVal = y;
			maxPos = x;
		}
	}

	//왼쪽에서는 마지막 maxPos가 나올 때까지 검사
	for (int i = 1; i < maxPos; i++) {
		if (a[i - 1] >= a[i]) {
			a[i] = a[i - 1];
		}
	}

	//오른쪽에서는 첫 maxPos까지 검사
	for (int i = 1000; i>maxPos; i--) {
		if (a[i + 1] >= a[i]) {
			a[i] = a[i + 1];
		}
	}

	//a를 변형시킨 후 누적합 s 계산
	for (int i = 1; i <= 1000; i++) {
		s[i] = s[i - 1] + a[i];
	}
	cout << s[1000];

	return 0;
}
