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

		//n을 넘지 않는 2의 승수 i로 n을 나눈 값의 총 합은 n!에서 2가 몇 번 곱해졌는지와 같다
		for (int i = 2; i <= n; i *= 2) {
			ret2 += n / i;
		}

		//n을 넘지 않는 5의 승수 i로 n을 나눈 값의 총 합은 n!에서 5가 몇 번 곱해졌는지와 같다
		for (int i = 5; i <= n; i *= 5) {
			ret5 += n / i;
		}
		ret = min(ret2, ret5); //최대공약수가 곧, 10이 몇 번 곱해졌는지와 같다
		cout << ret<<'\n';
	}
	
/*
수학적인 idea가 필요한 문제!
*/
	
	return 0;
}
