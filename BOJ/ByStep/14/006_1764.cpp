#include<iostream>
#include<map>
using namespace std;

int n, m, cnt;
string s;
map<string, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		mp[s]++;
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		mp[s]++;
	}

	for (pair<string,int> a : mp) {
		if (a.second == 2) cnt++;
	}
	cout << cnt << '\n';

	for (auto a : mp) {
		if (a.second == 2) cout << a.first << '\n';
	}

	return 0;
}
