#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[9], sum;
pair<int, int> idx;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < i; j++) {
			if (sum - a[i] - a[j] == 100) {
				idx.first = i, idx.second = j;
			}
		}
	}
	
	for (int i = 0; i < 9; i++) {
		if (i == idx.first || i == idx.second) continue;
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end()); //NlogN
	for (int i : v) cout << i << '\n';

	return 0;
}
