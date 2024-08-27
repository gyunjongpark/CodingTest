#include<iostream>
#define MAX 10000001 //0 ~ 10^7
using namespace std;

bool chae[MAX];

//에라토스테네스의 체 O(Nlog(logN))
void era(int n) { 
	for (int i = 2; i <= n; i++) chae[i] = true; //초기에는 전부 소수라고 가정

	for (int i = 2; i <= n; i++) {
		if (!chae[i]) continue; //소수가 아니라면 continue

		for (int j = i + i; j <= n; j += i) {
			chae[j] = false; //소수의 배수(소수가 아닌 수)들을 false로 전환
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	era(100);

	for (int i = 2; i <= 100; i++) {
		if (chae[i]) cout << i << ' ';
	}

	return 0;
}
