#include<iostream>
using namespace std;

int n, ret2, ret5;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 2; i <= n; i *= 2) {
		ret2 += n / i; // n!에서 2가 몇번 곱해져 있는가?
	}

	for (int i = 5; i <= n; i *= 5) {
		ret5 += n / i; // n!에서 5가 몇번 곱해져 있는가?
	}

	cout << min(ret2, ret5) << '\n';
  
	return 0;
}
