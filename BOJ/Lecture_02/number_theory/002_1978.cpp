#include<iostream>
#include<cmath>
using namespace std;

int n, temp, cnt;

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

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (check(temp)) cnt++;
	}
	cout << cnt;

	return 0;
}

/*
a*b=N에서 a>sqrt(N) && b>sqrt(N)인 순서쌍 (a,b)는 존재하지 않는다(N을 넘어버리므로)
a*b=N에서 sqrt(N)보다 작은 수 a와 sqrt(N)보다 큰 수 b가 서로 쌍을 이루기 때문에(a*b=N이므로)
sqrt(N)보다 작은 수 a로 나눠지는지만 조사한다면 자동으로 b도 조사하는 것이 된다(짝을 이루기 때문에)

즉, sqrt(n)보다 작은 범위에서 나눠지는지만 확인하면 된다
*/
