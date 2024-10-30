#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll n;
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	ll x = n;

	//보석을 여러 개 훔쳐갈 시, 보석끼리 달라붙으며 무게가 모든 보석들의 곱으로 늘어난다 -> 소인수 분해!
	//가장 작은 소인수부터 출력
	for (ll i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			v.push_back(i);
			x /= i;
		}
	}
  
	if (x != 1) v.push_back(x); //유일하게 sqrt(n)보다 큰 소인수가 있다면 출력

	cout << v.size() << '\n';
	for (ll l : v) cout << l << ' ';

	return 0;
}
