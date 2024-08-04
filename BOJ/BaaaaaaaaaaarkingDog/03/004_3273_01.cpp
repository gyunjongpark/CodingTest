#include<iostream>
using namespace std;

int n, x, answer, arr[1000001], ret[2000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> x;

	//O(N)
	for (int i = 0; i < n; i++) {
		if (x - arr[i] > 0 && ret[x - arr[i]]) { //짝을 찾으면
			answer++;
		}

		ret[arr[i]] = 1;
	}

	cout << answer;

	return 0;
}
