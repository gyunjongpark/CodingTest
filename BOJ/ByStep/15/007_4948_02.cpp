#include<iostream>
#include<vector>
using namespace std;

int n;
bool chae[250001]; //n <= 123456이므로 대충 2배인 25만

void era(int n) {
	chae[0] = false;
	chae[1] = false;

	for (int i = 2; i <= n; i++) {
		chae[i] = true;
	}

	for (int i = 2; i <= n; i++) {
		if (!chae[i]) continue; //이미 지워졌다면 continue

		for (int j = i + i; j <= n; j += i) {
			chae[j] = false; //i의 배수 지우기(소수만 남기기)
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	era(250000);

	while (true) {
		cin >> n;

		if (n == 0) break;

		int ret = 0;

		for (int i = n + 1; i <= 2 * n; i++) {
			if (chae[i]) ret++;
		}

		cout << ret << '\n';
	}

	return 0;
}
