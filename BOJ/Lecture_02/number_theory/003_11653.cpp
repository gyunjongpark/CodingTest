#include<iostream>
#include<cmath>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int x = n; //소인수 분해를 위한 변수 x
	for (int i = 2; i <= (int)sqrt(n); i++) {
		while (true) {
			if (x % i == 0) {
				cout << i << '\n';
				x /= i;
			}
			else break;
		}
	}
	if (x != 1) cout << x << '\n'; // sqrt(n) 이상의 소인수 존재 시 출력

	return 0;
}
