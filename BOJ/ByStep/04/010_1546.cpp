#include<iostream>
using namespace std;

double maxVal = -1, sum, a[1001];
int n;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > maxVal) maxVal = a[i];
	}

	for (int i = 0; i < n; i++) {
		a[i] = (double)a[i] / (double)maxVal * 100;
	}

	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	cout << sum / n;

	return 0;
}
