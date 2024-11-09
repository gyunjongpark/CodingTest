#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int n, m, temp;
map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	//O(NlogN)
	for (int i = 0; i < n; i++) { //N
		cin >> temp;
		mp[temp]++; //logN
	}

	cin >> m;

	//O(NlogN)
	for (int i = 0; i < m; i++) { //N
		cin >> temp;
		if (mp[temp]) cout << 1 << ' '; //logN
		else cout << 0 << ' ';
	}

	return 0;
}
