#include<iostream>
#include<cmath> //sqrt
#include<vector>
using namespace std;
typedef long long ll;

vector<ll> v;
ll k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;
	
	ll n = k; // 소인수 분해를 위한 변수 n
	for (int i = 2; i <= (int)sqrt(k); i++) {
		while (n % i == 0) {
			v.push_back(i);
			n /= i; // 같은 무게의 보석들은 줄줄이 딸려 나온다
		}
	}
	
	// sqrt(n)보다 큰 마지막 소인수가 있다면 출력
	if (n != 1) v.push_back(n);

	cout << v.size() << '\n';
	for (ll i : v) cout << i << ' ';

	return 0;
}
