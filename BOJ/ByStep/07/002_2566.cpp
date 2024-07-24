#include<iostream>
using namespace std;

int maxVal=-1, a[101][101];
pair<int, int> pi;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (maxVal < a[i][j]) {
				maxVal = a[i][j];
				pi.first = i + 1, pi.second = j + 1;
			}
		}
	}
	cout << maxVal << '\n';
	cout << pi.first << ' ' << pi.second;

	return 0;
}
