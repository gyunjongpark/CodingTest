#include<iostream>
using namespace std;

int sum, temp;
int minVal = 100;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	for (int i = 0; i < 7; i++) {
		cin >> temp;

		if (temp % 2) { //홀수라면
			sum += temp;
			minVal = min(minVal, temp);
		}
	}

	if (!sum) { //홀수가 존재하지 않아 합이 0이라면
		cout << -1;
	}
	else {
		cout << sum << '\n';
		cout << minVal;
	}

	return 0;
}
