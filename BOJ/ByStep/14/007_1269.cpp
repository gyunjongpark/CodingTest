#include<iostream>
#include<map>
using namespace std;

map<int, int> mp;
int n, m, temp, cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n + m; i++) {
		cin >> temp;
		mp[temp]++;
	}

	for (pair<int,int> i : mp) {
		if (i.second == 1) cnt++;
	}
	cout << cnt;

	return 0;
}
