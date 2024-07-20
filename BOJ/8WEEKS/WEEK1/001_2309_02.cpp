#include<iostream>
#include<algorithm> //sort
using namespace std;

int arr[9], sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + 9);

	do {
		int sum = 0;

		for (int i = 0; i < 7; i++) {
			sum += arr[i];
		}

		if (sum == 100) break;

	} while (next_permutation(arr, arr + 9)); // 배열의 값 switch

	for (int i = 0; i < 7; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}
