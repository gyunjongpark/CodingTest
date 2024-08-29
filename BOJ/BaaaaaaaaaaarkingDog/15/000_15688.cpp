#include<iostream>
#include<algorithm>
#include<climits> //INT_MAX
using namespace std;

int n, temp, cnt[2000002];
int maxVal = INT_MIN, minVal = INT_MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		temp += 1000000;

		minVal = min(minVal, temp);
		maxVal = max(maxVal, temp);
		cnt[temp]++;
	}

	for (int i = 0; i <= maxVal; i++) {
		for (int j = 1; j <= cnt[i]; j++) {
			cout << i - 1000000 << '\n';
		}
	}

	return 0;
}
