#include<iostream>
#define MAX 1004
using namespace std;

int n;
double maxVal = -1, sum, a[MAX];

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
