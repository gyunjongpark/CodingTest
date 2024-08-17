#include<iostream>
using namespace std;

string a[65][65], s;
int n;

string recur(int y, int x, int size) {
	if (size == 1) return a[y][x];

	string ret = "";

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (a[y][x] != a[i][j]) {

				// divide and conquer
				ret += "(";
				ret += recur(y, x, size / 2);
				ret += recur(y, x + size / 2, size / 2);
				ret += recur(y + size / 2, x, size / 2);
				ret += recur(y + size / 2, x + size / 2, size / 2);
				ret += ")";

				return ret;
			}
		}
	}

	// 배열 전체가 같다면
	return a[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
		}
	}

	cout << recur(0, 0, n);

	return 0;
}
