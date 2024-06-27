#include<iostream>
#define MAX 14
using namespace std;

int a[MAX], temp, maxVal = -1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		if (a[i] > maxVal) {
			maxVal = a[i];
			temp = i;
		}
	}
	cout << maxVal << '\n' << temp + 1;

	return 0;
}
