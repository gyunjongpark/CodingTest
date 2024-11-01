#include<iostream>
using namespace std;

int n, t[16], p[16]; //1 ≤ T[i] ≤ 5, 1 ≤ P[i] ≤ 1,000
int ret = -1;

void recur(int day, int pay) {
	if (day > n) return;
	if (day == n) {
		ret = max(ret, pay);
		return; //최댓값의 경우 idx가 n까지 도달해야 값을 확정 지을 수 있다
	}

	recur(day + t[day], pay + p[day]);
	recur(day + 1, pay);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}

	recur(0, 0);

	cout << ret;

	return 0;
}
