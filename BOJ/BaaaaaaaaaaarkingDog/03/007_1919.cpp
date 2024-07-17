#include<iostream>
#include<cmath> //abs
using namespace std;

string a, b;
int cnt[2][26], ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	for (char c : a) {
		cnt[0][c - 'a']++;
	}

	for (char c : b) {
		cnt[1][c - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		ret += abs(cnt[0][i] - cnt[1][i]);
	}

	cout << ret;

	return 0;
}
