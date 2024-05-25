#include<iostream>
using namespace std;

int ret, ret2, ret5, t, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;

		ret2 = ret5 = ret = 0;

		for (int i = 2; i <= n; i *= 2) {
			ret2 += n / i;
		}
		for (int i = 5; i <= n; i *= 5) {
			ret5 += n / i;
		}
		ret = min(ret2, ret5);
		cout << ret<<'\n';
	}

/*
수학적인 idea가 필요한 문제
*/

	return 0;
}
