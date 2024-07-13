#include<iostream>
using namespace std;

int n, a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	a = n / 5;
	while (true) {
		if (a < 0) {
			cout << -1;
			return 0; //즉시 종료
		}

		if ((n - a * 5) % 3 == 0) {
			b = (n - a * 5) / 3;
			break; //n이 5와 3으로 정확하게 분할된다면 break
		}
		a--; //정확하게 나눌 수 없는 경우 a를 줄이고 b로 다시 분할해보기
	}
	cout << a + b;

	return 0;
}
