#include<iostream>
#define MAX 104
using namespace std;

int a, b, t, ret;
int arr[MAX][MAX];

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> t;

	while (t--) {
		cin >> a >> b;
		for (int i = a; i < a + 10; i++) {
			for (int j = b; j < b + 10; j++) {
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			ret += arr[i][j];
		}
	}
	cout << ret;

	return 0;
}
