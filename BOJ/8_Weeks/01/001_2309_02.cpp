#include<iostream>
#include<algorithm> //sort, next_permutation
using namespace std;

int arr[9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + 9);

	do {
		int sum = 0;
    
		for (int i = 0; i < 7; i++) {
			sum += arr[i];
		}

		if (sum == 100) break; //반드시 탈출 조건을 명시해야 한다
	} while (next_permutation(arr, arr + 9)); //next_permutation : 순열 무한 반복

	for (int i = 0; i < 7; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}
