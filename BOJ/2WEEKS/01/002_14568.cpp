#include<iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int cnt = 0;
	for (int i = 1; i <= n; i++) { // 택희
		for (int j = 1; j <= n; j++) { // 영훈
			for (int k = 1; k <= n; k++) { // 남규
				if (i + j + k == n && k >= j + 2 && (i % 2 == 0)) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;
	
	return 0;
}
