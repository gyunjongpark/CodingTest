#include<iostream>
#include<vector>
using namespace std;

int n, temp, ret, chae[1004];

void era(int n) { //에라토스테네스의 체로 chae 배열 먼저 완성
	for (int i = 2; i <= n; i++) {
		if (chae[i]) continue;

		for (int j = i + i; j <= n; j += i) {
			chae[j] = 1;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	era(1001); //수는 1,000 이하의 자연수이다

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == 1) continue; //1은 소수가 아니므로 continue

		if (!chae[temp]) ret++;
	}

	cout << ret;

	return 0;
}
