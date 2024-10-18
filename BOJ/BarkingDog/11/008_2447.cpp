#include<iostream>
using namespace std;

string a[65][65], s;
int n;

void recur(int i, int j, int n) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
		cout << ' '; //중앙은 공백
		return;
	}
	else {
		if (n / 3 == 0) { //n = 3 ^ 0 = 1일 때
			cout << '*';
			return;
		}
		else recur(i, j, n / 3); //아직 n = 3, 9, 27...이라면 재귀
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
