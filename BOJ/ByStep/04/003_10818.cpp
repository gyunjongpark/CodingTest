#include<iostream>
using namespace std;

int n, temp, minVal = 1000004, maxVal = -1000004;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp > maxVal) maxVal = temp;
		if (temp < minVal) minVal = temp;
	}
	cout << minVal << ' ' << maxVal;

	return 0;
}
