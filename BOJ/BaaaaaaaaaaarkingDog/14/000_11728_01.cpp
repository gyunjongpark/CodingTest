//merge sort logic

#include<iostream>
#include<climits> //INT_MAX
using namespace std;

int n, m, a[1000001], b[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	a[n] = INT_MAX, b[m] = INT_MAX;

	int idx_a = 0, idx_b = 0;

	while (true) {
		if (idx_a == n && idx_b == m) break;

		if (a[idx_a] >= b[idx_b]) {
			cout << b[idx_b] << ' ';
			idx_b++;
		}
		else {
			cout << a[idx_a] << ' ';
			idx_a++;
		}
	}

	return 0;
}
