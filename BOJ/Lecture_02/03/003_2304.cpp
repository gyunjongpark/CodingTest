#include<iostream>
#define MAX 504
using namespace std;

int n, m, temp, sum, a[MAX];
int maxPos, maxVal, maxVal_front, maxVal_back;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= m; i++) { //a[1] ~ a[m]
		cin >> temp;
		a[i] = temp;

		if (temp >= maxVal) {
			maxVal = temp;
			maxPos = i;
		}
	}

	//왼쪽부터 maxPos 직전까지 검사, a[1]은 비교 대상 없이 그대로
	for (int i = 2; i < maxPos; i++) {
		if (a[i - 1] >= a[i]) {
			maxVal_front = a[i - 1];
			sum += maxVal_front - a[i];
			a[i] = maxVal_front;
		}
		else maxVal_front = a[i];
	}

	//오른쪽부터 maxPos 직전까지 검사, a[m]은 비교 대상 없이 그대로
	for (int i = m - 1; i > maxPos; i--) {
		if (a[i + 1] >= a[i]) {
			maxVal_back = a[i + 1];
			sum += maxVal_back - a[i];
			a[i] = maxVal_back;
		}
		else maxVal_back = a[i];
	}
	cout << sum;

	return 0;
}
