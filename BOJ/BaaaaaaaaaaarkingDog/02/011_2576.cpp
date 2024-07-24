#include<iostream>
using namespace std;

int sum, temp;
int minVal = 100;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	for (int i = 0; i < 7; i++) {
		cin >> temp;
		
		if (temp % 2) {
			sum += temp;
			minVal = min(minVal, temp);
		}
	}

	if (!sum) {
		cout << -1;
	}
	else {
		cout << sum << '\n';
		cout << minVal;
	}

	return 0;
}
