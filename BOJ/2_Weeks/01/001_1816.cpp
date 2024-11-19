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
		cin >> n; //10 ^ 12 ≤ S ≤ 10 ^ 18

		bool flag = true; //적절한 암호라고 가정

		for (int i = 2; i < 1000001; i++) {
			if (n % i == 0) {
				flag = false; //나눠지면 false
				break;
			}
		}

		if (!flag) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}
