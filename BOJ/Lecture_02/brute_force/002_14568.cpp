#include<iostream>
using namespace std;

int n, cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) { //택희
		for (int j = 0; j < n; j++) { //영훈
			for (int k = 0; k < n; k++) { //남규
				if (i == 0 || j == 0 || k == 0) continue; //조건 3
				if (i % 2) continue; //조건 4
				if (i + j + k == n && k >= j + 2) { //조건1, 조건2
					cnt++;
				}
			}
		}
	}
	cout << cnt;

	return 0;
}
