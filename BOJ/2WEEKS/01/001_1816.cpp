#include<iostream>
using namespace std;
typedef long long ll;

bool flag;
int n;
ll s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> s; // init
		flag = 0; // init
		
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
