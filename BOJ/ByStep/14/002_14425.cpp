#include<iostream>
#include<map>
using namespace std;

map<string, int> mp;
int cnt, n, m;
string s;

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
		if (mp[s]) cnt++;
	}
	cout << cnt;

	return 0;
}
