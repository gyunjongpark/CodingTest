#include<iostream>
using namespace std;

char a[16][16];
string s;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			a[i][j] = s[j];
		}
	}

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (a[j][i] == 0) continue; //null이면 continue
			cout << a[j][i];
		}
	}

	return 0;
}
