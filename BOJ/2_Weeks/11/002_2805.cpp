#include<iostream>
#include<algorithm> //sort
using namespace std;
typedef long long ll;

ll n, m, ret;
int tree[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}

	sort(tree, tree + n);

	ll l = 0, r = tree[n - 1];

	while (l <= r) {
		ll wood = 0;
		ll cut = (l + r) / 2;

		for (int i = 0; i < n; i++) {
			if (tree[i] - cut > 0) {
				wood += tree[i] - cut;
			}
		}

		if (wood >= m) {
			ret = cut;
			l = cut + 1;
		}
		else {
			r = cut - 1;
		}
	}

	cout << ret;

	return 0;
}
