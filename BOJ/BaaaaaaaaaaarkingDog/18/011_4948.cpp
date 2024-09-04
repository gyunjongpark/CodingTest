#include<iostream>
using namespace std;

bool chae[250001];
int n;

void era(int n) {
	for (int i = 2; i <= n; i++) {
		if (chae[i]) continue; //이미 소수가 아니라면 continue

		for (int j = i + i; j <= n; j += i) {
			if (chae[j]) continue; //이미 소수가 아니라면 continue
			chae[j] = true; //소수가 아닌 수 true
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	era(250001); //n <= 123456

	while (true) {
		cin >> n;

		if (n == 0) break;

		int ret = 0;

		for (int i = n + 1; i <= 2 * n; i++) {
			if (!chae[i]) ret++;
		}

		cout << ret << '\n';
	}

	return 0;
}
