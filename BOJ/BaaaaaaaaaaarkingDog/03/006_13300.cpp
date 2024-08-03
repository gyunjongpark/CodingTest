#include<iostream>
using namespace std;

int n, k, s, g, ret, arr[2][7];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> s >> g;
		arr[s][g]++;
	}

	//s는 0 or 1, g는 1 ~ 6
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 7; j++) {
			if (arr[i][j] % k) {
				ret += (arr[i][j] / k) + 1;
			}
			else ret += arr[i][j] / k;
		}
	}
	cout << ret;

	return 0;
}
