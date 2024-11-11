#include<iostream>
#include<algorithm> //sort
#include<vector>
using namespace std;

int n, temp, m, num;
vector<int> v;

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
		cin >> num;

		if (binary_search(v.begin(), v.end(), num)) {
			cout << 1 << ' ';
		}
		else {
			cout << 0 << ' ';
		}
	}

	return 0;
}
