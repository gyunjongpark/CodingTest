#include<iostream>
#include<algorithm> //sort
using namespace std;
typedef long long ll;

int n, m, ret;
int tree[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}

	sort(tree, tree + n);

	int l = 0, r = tree[n - 1];

	while (l <= r) {
		int mid = (l + r + 1) / 2;
		ll wood = 0;

		for (int i = 0; i < n; i++) {
			if (tree[i] - mid > 0) {
				wood += tree[i] - mid;
			}
		}

		if (wood >= m) {
			ret = max(ret, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << ret;

	return 0;
}
