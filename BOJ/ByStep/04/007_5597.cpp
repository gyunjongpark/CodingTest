#include<iostream>
using namespace std;

int arr[31], num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 28; i++) {
		cin >> num;
		arr[num] = num; //1번부터 30번까지 출석번호가 붙어 있다
	}

	for (int i = 1; i <= 30; i++) {
		if (arr[i] != i) {
			cout << i << '\n';
		}	
	}

	return 0;
}
