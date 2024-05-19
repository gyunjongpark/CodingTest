#include<iostream>
using namespace std;

int n, cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) { //남규
		for (int j = 0; j < n; j++) { //영훈
			for (int k = 0; k < n; k++) { //택희
				if (i < 1 || j < 1 || k < 1 || k % 2) continue;
				if (n == i + j + k && i >= j + 2) cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}
