#include<iostream>
#include<algorithm>
using namespace std;

int a[1001];
int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n); // O(NlogN)
	reverse(a, a + n); // O(N)

	cout << a[k - 1];

	return 0;
}
