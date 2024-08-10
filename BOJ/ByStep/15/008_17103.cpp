#include<iostream>
using namespace std;

int t, n;
bool chae[1000001];


//n의 범위 100만까지 배열 완성
void era() {
	for (int i = 2; i <= 1000000; i++) {
		chae[i] = true;
	}

	for (int i = 2; i <= 1000000; i++) {
		if (!chae[i]) continue; //소수가 아니면 continue

		for (int j = i + i; j <= 1000000; j += i) {
			chae[j] = false; //본인을 제외한 배수 false
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	era(); //에라토스테네스의 체로 최대 범위 내 소수 배열 chae 완성

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
