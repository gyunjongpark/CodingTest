#include<iostream>
using namespace std;

int t, n;
bool chae[1000001];

void era(int num) {

	chae[0] = false;
	chae[1] = false;

	for (int i = 2; i <= num; i++) {
		chae[i] = true;
	}

	for (int i = 2; i <= num; i++) {
		if (!chae[i]) continue;

		for (int j = i + i; j <= num; j += i) {
			chae[j] = false;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	era(1000000);

	cin >> t;

	while (t--) {
		cin >> n;

		int cnt = 0;

		//골드바흐의 추측: 2보다 큰 짝수는 두 소수의 합으로 나타낼 수 있다
		for (int i = 2; i <= n / 2; i++) {
			if (chae[i] && chae[n - i]) {
				cnt++;
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}
