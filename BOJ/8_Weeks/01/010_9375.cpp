#include<iostream>
#include<map>
using namespace std;

int t, n;

string clothes, type;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n;

		map<string, int> mp;

		for (int i = 0; i < n; i++) {
			cin >> clothes >> type;
			mp[type]++;
		}

		int ret = 1;

		for (pair<string, int> pi : mp) {
			ret *= (pi.second + 1);
		}

		ret--; //아무것도 입지 않은 경우 제외

		cout << ret << '\n';
	}

	return 0;
}
