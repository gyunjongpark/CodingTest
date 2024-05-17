#include<iostream>
#include<vector>
using namespace std;

//O(N^2)
void selectSort(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		int minVal = 1e6; int idx = -1;
		
		for (int j = i; j < v.size(); j++) {
			if (v[j] < minVal) {
				minVal = v[j];
				idx = j;
			}
		}
		int temp = v[i];
		v[i] = v[idx];
		v[idx] = temp;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	selectSort(v);

	for (int i : v) cout << i << '\n';

	return 0;
}
