#include<iostream>
using namespace std;
typedef long long ll;

ll a, b;

ll getGCD(ll a, ll b) {
	if (a == 0) return b;
	return getGCD(b % a, a);
}

ll getLCM(ll a, ll b) {
	return a * b / getGCD(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	cout << getLCM(a, b) << '\n';

	return 0;
}
