#include<iostream>
#include<map>
using namespace std;

int t, n;

string cloth, type;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	
	while (t--) {
		cin >> n;

		map<string, int> mp; // TC마다 초기화
		for (int i = 0; i < n; i++) {
			cin >> cloth >> type;
			mp[type]++;
		}

		int ret = 1; // TC마다 초기화
		for (pair<string, int> pi : mp) {
			ret *= (pi.second + 1);	
		}

		ret--;
		cout << ret << '\n';
	}

	return 0;
}
