#include<iostream>
#define MAX 34
using namespace std;

int arr[MAX], num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 28; i++) {
		cin >> num;
		arr[num - 1] = num;
	}
	for (int i = 0; i < 30; i++) {
		if (arr[i] != i + 1)
			cout << i + 1 << '\n';
	}

	return 0;
}
