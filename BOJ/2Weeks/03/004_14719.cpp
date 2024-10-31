#include<iostream>
using namespace std;

int n, m, temp, a[501], ret;
int maxVal, maxPos, maxVal_front, maxVal_back;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> temp;

		a[i] = temp;

		if (temp >= maxVal) {
			maxVal = temp;
			maxPos = i;
		}
	}

	for (int i = 2; i < maxPos; i++) {
		if (a[i - 1] >= a[i]) {
			maxVal_front = a[i - 1];
			ret += maxVal_front - a[i];
			a[i] = maxVal_front;
		}
		else maxVal_front = a[i];
	}

	for (int i = 499; i > maxPos; i--) {
		if (a[i + 1] >= a[i]) {
			maxVal_back = a[i + 1];
			ret += maxVal_back - a[i];
			a[i] = maxVal_back;
		}
		else maxVal_back = a[i];
	}

	cout << ret;

	return 0;
}
