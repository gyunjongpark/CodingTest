#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int a[9];
pair<int, int> pi;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}

	//시간과 메모리가 허용된다면 완전탐색을 먼저 떠올린다
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < i; j++) {
			if (sum - a[i] - a[j] == 100) {
				pi.first = i, pi.second = j;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i == pi.first || i == pi.second) continue;
		v.push_back(a[i]);
	}

	sort(v.begin(), v.end());

	for (int i : v) cout << i << '\n';

	return 0;
}
