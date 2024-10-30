#include<iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int x = n;

  //가장 작은 소인수부터 출력
	for (int i = 2; i * i <= n; i++) {
		while (x % i == 0) {
			cout << i << '\n';
			x /= i;
		}
	}

  //sqrt(n)보다 큰 소인수는 최대 1개 존재한다
  //2개 이상이라면 전체 소인수들의 곱이 n을 넘어서므로 모순이다
	if (x != 1) cout << x << '\n'; //유일하게 sqrt(n)보다 큰 소인수가 있다면 출력

	return 0;
}
