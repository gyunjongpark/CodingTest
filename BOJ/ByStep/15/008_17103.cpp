#include<iostream>
#define MAX 1000004
using namespace std;

int t, n;
bool chae[MAX];

void era() {
	for (int i = 2; i <= MAX; i++) {
		chae[i] = true;
	}

	for (int i = 2; i <= MAX; i++) {
		if (!chae[i]) continue; //소수가 아니면 continue

		for (int j = i + i; j <= MAX; j += i) {
			chae[j] = false; //본인을 제외한 배수 false
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	era(); //에라토스테네스의 체로 최대 범위 내 소수 구하기
	
	cin >> t;

	while (t--) {
		cin >> n;

		if (n == 0) break;

		int cnt = 0;
		for (int i = 2; i <= n / 2; i++) {
			if (chae[i] && chae[n - i]) {
				cnt++;
			}
		}
    
		cout << cnt << '\n';
	}

	return 0;
}
