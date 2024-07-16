#include<iostream>
#include<cmath> //sqrt
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
a * b = N을 만족하면서 a>sqrt(N) && b>sqrt(N)인 순서쌍 (a,b)는 N을 넘어버리므로 존재하지 않는다
다시 말해 a * b = N에서 a가 sqrt(N)보다 큰 수라면 항상 sqrt(N)보다 작은 수 b와 서로 쌍을 이루게 된다
따라서, sqrt(N)보다 작은 수 a로 나눠지는지만 조사한다면 그의 짝인 b 또한 자동으로 조사하는 것이 된다

-> sqrt(n)보다 작은 범위에서 나눠지는지만 확인하면 된다
*/
