#include<iostream>
#include<algorithm> //reverse
using namespace std;

int arr[20], s, e;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (int i = 0; i < 20; i++) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < 10; i++) {
		cin >> s >> e;

		//arr.begin()은 첫번째 원소를 가리키고, arr.end()는 마지막 원소 다음 위치를 가리킨다
		reverse(arr + s - 1, arr + e);
	}

	for (int i : arr) {
		cout << i << ' ';
	}

	return 0;
}
