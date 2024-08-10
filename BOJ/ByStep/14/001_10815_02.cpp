#include<iostream>
#include<algorithm> //sort
#include<vector>
using namespace std;

int n, m, num, temp;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	
	sort(v.begin(), v.end()); //O(NlogN)

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> num;

		//O(logN), binary_search는 정렬된 배열에만 적용할 수 있다
		if (binary_search(v.begin(), v.end(), num)) {
			cout << 1 << ' ';
		}
		else cout << 0 << ' ';
	}

	return 0;
}
