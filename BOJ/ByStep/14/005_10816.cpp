#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, temp;
vector<int> v, v1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> temp;
		v1.push_back(temp);
	}

	for (int a : v1) {
		cout << upper_bound(v.begin(), v.end(), a) - lower_bound(v.begin(), v.end(), a) << ' ';
	}

	return 0;
}
