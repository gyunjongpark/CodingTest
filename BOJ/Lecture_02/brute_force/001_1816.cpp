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
		bool flag = 0; //init
		cin >> s; //암호 입력

		for (int i = 2; i < 1000001; i++) {
			if (s % i == 0) {
				flag = 1;
				break;
			}
		}
		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}
