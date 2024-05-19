#include<iostream>
using namespace std;
typedef long long ll;

int n;
ll s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> s;
		bool flag = 1;

		for (int i = 2; i <= 1000000; i++) {
			if (s % i == 0) {
				cout << "NO\n";
				flag = 0;
				break;
			}
		}

		if (flag) cout << "YES\n";
	}

	return 0;
}
