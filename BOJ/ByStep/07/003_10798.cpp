#include<iostream>
using namespace std;

char a[16][16]; //전역변수로 선언되었으므로 배열의 값은 0으로 초기화
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

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (a[j][i] == 0) {
				continue; //null이면 continue
			}

			cout << a[j][i];
		}
	}

	return 0;
}
