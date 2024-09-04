#include<iostream>
using namespace std;

bool chae[1000001];
int n, m;

void era(int n) { //O(Nlog(logN))
	for (int i = 2; i <= n; i++) {
		if (chae[i]) continue; //이미 소수가 아니라면 continue

		for (int j = i + i; j <= n; j += i) {
			chae[j] = true; //소수가 아닌 수 true
		}	
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	era(1000001); //n, m은 100만 이하의 자연수

	cin >> n >> m;

	for (int i = n; i <= m; i++) {
		if (i == 1) continue; //1은 소수가 아니므로 제외
		if (!chae[i]) cout << i << '\n';
	}

	return 0;
}
