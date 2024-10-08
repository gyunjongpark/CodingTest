#include<iostream>
using namespace std;

int t, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n; //init
		int ret2 = 0; //init
		int ret5 = 0; //init

		for (int i = 2; i <= n; i *= 2) {
			ret2 += n / i; //n!에서 2가 몇 번 곱해져 있는가?
		}

		for (int i = 5; i <= n; i *= 5) {
			ret5 += n / i; //n!에서 5가 몇 번 곱해져 있는가?
		}

    		//최솟값을 구하면 n!에서 10이 몇 번 곱해져 있는지(0이 몇 개 존재하는지) 구할 수 있다
		cout << min(ret2, ret5) << '\n';
	}

	return 0;
}
