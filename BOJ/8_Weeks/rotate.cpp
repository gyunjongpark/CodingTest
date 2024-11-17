#include<iostream>
#include<vector>
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

	//1차원 배열 회전
	vector<int> arr{ 1,2,3,4,5 };
	rotate(arr.begin(), arr.begin() + 1, arr.end()); //rotate(시작 iterator, 몇 칸?, 끝 이터레이터) 반시계 방향 회전
	for (int i : arr) cout << i << ' '; cout << '\n'; //2 3 4 5 1

	rotate(arr.rbegin(), arr.rbegin() + 1, arr.rend()); //rotate(시작 iterator, 몇 칸?, 끝 이터레이터) 시계 방향 회전
	for (int i : arr) cout << i << ' '; cout << '\n'; //1 2 3 4 5

	cout << '\n';

	//2차원 배열 회전
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

	rotate(a); cout << '\n';

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << ret[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}
