#include<iostream>
using namespace std;

int a[9], idx;
int maxVal = -1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> a[i];

		if (a[i] > maxVal) {
			maxVal = a[i];
			idx = i;
		}
	}

	cout << maxVal << '\n' << idx + 1;

	return 0;
}
