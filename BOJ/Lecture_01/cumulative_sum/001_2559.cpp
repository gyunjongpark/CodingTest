#include<iostream>
using namespace std;

int n, k, temp;
int psum[100004];
int maxVal = -10000004;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> temp;
		psum[i] = psum[i - 1] + temp;
	}

	for (int i = k; i <= n; i++) {
		maxVal = max(maxVal, (psum[i] - psum[i - k]));
	}
	cout << maxVal;

	return 0;
}
