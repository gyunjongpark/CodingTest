#include<iostream>
#include<vector>
using namespace std;

int n, k;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			v.push_back(i);
		}
	}

	if (v.size() < k) {
		cout << 0;
	}
	else {
		cout << v[k - 1];
	}

	return 0;
}
