#include<iostream>
#include<cmath> //sqrt
using namespace std;

int n, m, ret, minVal=1e6;

bool check(int n) {
	if (n <= 1) return 0;
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) return 0;
	}
  
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = m; i >= n; i--) {
		if (check(i)) {
			ret += i;
			minVal = i;
		}
	}
	if (ret == 0) cout << -1;
	else cout << ret << '\n' << minVal;

	return 0;
}
