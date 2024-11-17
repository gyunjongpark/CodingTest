#include<iostream>
using namespace std;

int ret[3][2];

void rotate(int a[2][3]) {
	for (int i = 0; i < 2; i++) { //r = 2
		for (int j = 0; j < 3; j++) { //c = 3
			ret[3 - j - 1][i] = a[i][j]; //반시계 방향 회전 ret[c - j - 1][i] = a[i][j]
			//ret[j][2 - i - 1] = a[i][j]; //시계 방향 회전 ret[j][r - i - 1] = a[i][j]
		}
	}

	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a[2][3] = { //r = 2, c = 3
		{1,2,3},
		{4,5,6}
	};

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j] << ' ';
		}

		cout << '\n';
	}

	rotate(a);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << ret[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}
