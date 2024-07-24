#include<iostream>
using namespace std;

int N, X, arr[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> X;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		if (arr[i] < X) {
			cout << arr[i] << ' ';
		}
	}

	return 0;
}
