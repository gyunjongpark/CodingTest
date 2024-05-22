#include<iostream>
#include<map>
using namespace std;

int t, n;
string a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	
	while (t--) {

		cin >> n;

		map<string, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> a >> b; //이름과 종류
			mp[b]++; //종류만 count
		}

		int ret = 1;
		for (pair<string,int> it : mp) {
			if (it.second > 0) {
				ret *= it.second + 1;
			}
		}
		ret--;

		cout << ret<<'\n';
	}

	return 0;
}
