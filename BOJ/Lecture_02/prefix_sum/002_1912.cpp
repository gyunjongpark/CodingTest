#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;

int n, temp, maxVal, s[MAX], a[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	fill(&s[0], &s[0] + MAX, -1001);

	for (int i = 1; i <= n; i++) {
		s[i] = max(s[i - 1] + a[i], a[i]);
	}
	cout << *(max_element(s, s + (n + 1)));

	return 0;
}
