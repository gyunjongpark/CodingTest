#include<iostream>
#include<algorithm> //sort, upper_bound, lower_bound
#include<vector>
using namespace std;

int n, m, temp;
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

	//upper_bound, lower_bound를 이용한 풀이
	for (int i = 0; i < m; i++) {
		cin >> temp;
		cout << upper_bound(v.begin(), v.end(), temp) - lower_bound(v.begin(), v.end(), temp) << ' ';
	}

	return 0;
}
