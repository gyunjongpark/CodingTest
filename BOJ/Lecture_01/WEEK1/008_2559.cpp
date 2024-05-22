#include<iostream>
#define MAX 100001
using namespace std;

int n, k, temp, s[MAX];
int maxVal = -10000001; //최악의 경우 -100 * 10만

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	//누적합
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		s[i] = s[i - 1] + temp;
	}

	for (int i = k; i <= n; i++) {
		maxVal = max(maxVal, (s[i] - s[i - k]));
	}
	cout << maxVal;

	return 0;
}
