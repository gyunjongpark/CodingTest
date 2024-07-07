#include<iostream>
#define MAX 100004
using namespace std;

int n, k, temp, s[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> temp;
		s[i] = s[i - 1] + temp;
	}

	int maxVal = -MAX * 100; //최악의 경우 -100*10만
	for (int i = k; i <= n; i++) {
		maxVal = max(maxVal, (s[i] - s[i - k]));
	}
	cout << maxVal;

	return 0;
}
