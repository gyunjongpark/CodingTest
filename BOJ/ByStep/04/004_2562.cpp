#include<iostream>
using namespace std;

int a[9], temp, maxVal; //배열 a의 원소는 자연수이므로 maxVal = 0으로 초기화해도 무방하다

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		
		if (a[i] > maxVal) {
			maxVal = a[i];
			temp = i;
		}
	}
	
	cout << maxVal << '\n' << temp + 1;

	return 0;
}
