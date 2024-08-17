#include<iostream>
using namespace std;

int n;

void recur(int i, int j, int num) {
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1) cout << ' '; //중앙은 공백
	else {
		if (num / 3 == 0) cout << '*'; //num은 3의 승수, num / 3 == 0인 경우는 num = 1일 때 *
		else recur(i, j, num / 3); //num = 1이 아니라면 재귀
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			recur(i, j, n);
		}

		cout << '\n';
	}

	return 0;
}
