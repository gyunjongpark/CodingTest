#include<iostream>
using namespace std;
typedef long long ll;

int t;
ll n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n;

		bool flag = true; //적절하면 true

		for (int i = 2; i < 1000001; i++) {
			if (n % i == 0) {
				flag = false; //나눠지면 소수가 아니므로 적절하지 않음
				break;
			}
		}

		if (!flag) cout << "NO\n"; //적절하지 않으면 NO
		else cout << "YES\n";
	}

	return 0;
}
