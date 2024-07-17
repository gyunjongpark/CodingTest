#include<iostream>
#include<algorithm> //max_element, min_element
using namespace std;

int arr[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	int maxVal = *(max_element(arr, arr + 3));
	int minVal = *(min_element(arr, arr + 3));

	int midVal = -1;

	for (int i = 0; i < 3; i++) {
		if (arr[i] != maxVal && arr[i] != minVal) {
			midVal = arr[i];
		}
	}

	cout << minVal << ' ' << midVal << ' ' << maxVal;

	return 0;
}
