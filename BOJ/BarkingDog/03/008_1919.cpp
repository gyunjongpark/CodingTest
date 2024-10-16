#include<iostream>
#include<cmath> //abs
using namespace std;

string a, b;
int ret, cnt1[26], cnt2[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	for (char c : a) {
		cnt1[c - 'a']++;
	}

	for (char c : b) {
		cnt2[c - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		ret += abs(cnt1[i] - cnt2[i]);
	}

	cout << ret;

	return 0;
}
