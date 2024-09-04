#include<iostream>
using namespace std;

bool chae[1001];
int n, temp, ret;

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

	era(1001); //n은 1000 이하의 자연수

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		
		if (temp == 1) continue; //1은 소수가 아니므로 제외
		if (!chae[temp]) ret++;
	}

	cout << ret;

	return 0;
}
