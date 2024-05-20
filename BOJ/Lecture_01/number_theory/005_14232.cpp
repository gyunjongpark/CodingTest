#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;

ll n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	ll x = n;
	vector<ll> v;

  //보석들의 최대 개수 : 소인수분해
	for (int i = 2; i <= (int)sqrt(n); i++) {
		while (x % i == 0) {
			v.push_back(i);
			x /= i;
		}
	}
	if (x != 1) v.push_back(x);

	cout << v.size() << '\n';
	for (ll i : v) cout << i << ' ';

	return 0;
}
