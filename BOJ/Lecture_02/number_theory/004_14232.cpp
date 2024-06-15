#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;

ll k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;

	ll n = k;
	vector<ll> v;

	for (int i = 2; i <= (int)sqrt(n); i++) {
		while (n % i == 0) {
			v.push_back(i);
			n /= i;
		}
	}
	if (n != 1) v.push_back(n); //마지막 소인수

	cout << v.size() << '\n';
	for (ll i : v) cout << i << ' ';

	return 0;
}
