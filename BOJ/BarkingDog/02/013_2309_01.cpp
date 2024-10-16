#include<iostream>
#include<algorithm> //sort
using namespace std;

int arr[9], sum;
pair<int, int> not_dwarf;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + 9);

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				not_dwarf = { i,j };
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i == not_dwarf.first || i == not_dwarf.second) continue;

		cout << arr[i] << '\n';
	}

	return 0;
}
