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
	
	/*
	sqrt(n)까지만 조사해도 되는 이유
	n=p*q에서 p>sqrt(n) && q>sqrt(n)인 합성수는 존재하지 않음
 	p>sqrt(n)라면 반드시 q<sqrt(n)이어야 함
  	따라서, 제곱근보다 큰 소인수는 많아야 한 개이다.
	*/

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
