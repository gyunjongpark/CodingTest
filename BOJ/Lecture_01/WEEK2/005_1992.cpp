#include<iostream>
#define MAX 65
using namespace std;

string a[MAX][MAX], s;
int n;

string quad(int y, int x, int size) { //기준 좌표, size
	if (size == 1) return a[y][x]; //size가 1이라면 그대로 반환
	
	string ret = "";
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (a[y][x] != a[i][j]) {
				ret += "(";
				ret += quad(y, x, size / 2);
				ret += quad(y, x + size / 2, size / 2);
				ret += quad(y + size / 2, x, size / 2);
				ret += quad(y + size / 2, x + size / 2, size / 2);
				ret += ")";

				return ret;
			}
		}
	}
	//반복문 통과. 전체가 1이거나 0
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
	cout << quad(0, 0, n); //divide and conquer

	return 0;
}
