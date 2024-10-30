#include<iostream>
using namespace std;

int n, temp, ret;

bool check(int n) {
	if (n <= 1) return false;

  //n의 제곱근 이하의 수는 반드시 n의 제곱근 이상의 수와 곱해져 n을 완성한다
  //따라서 n의 제곱근 이하의 수까지만 확인해도 그 이상의 수 또한 검사하는 꼴이다
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;

		if (check(temp)) ret++;
	}

	cout << ret;

	return 0;
}
