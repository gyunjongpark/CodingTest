#include<iostream>
#include<vector>
#define MAX 1000004
using namespace std;
typedef long long ll;

int n, arr[MAX], a, b;
ll ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	ret = n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; //rooms for exam
	}

	cin >> a >> b;

	for (int i = 0; i < n; i++) {
		arr[i] -= a;
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) continue;
      
		ret += arr[i] / b;

		if (arr[i] % b) ret++;
	}
	cout << ret;

	return 0;
}
