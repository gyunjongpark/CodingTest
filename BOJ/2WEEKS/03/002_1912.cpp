#include<iostream>
using namespace std;

int n, temp, s[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	fill(&s[0], &s[0] + 100001, -1001);

	for (int i = 1; i <= n; i++) {
		cin >> temp;
		s[i] = max(s[i - 1] + temp, temp);
	}

	int maxVal = s[1]; // 첫번째 요소부터 검사

	for (int i = 1; i <= n; i++) {
		maxVal = max(maxVal, s[i]);
	}
	cout << maxVal;

	return 0;
}
