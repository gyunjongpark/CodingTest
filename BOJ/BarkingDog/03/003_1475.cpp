#include<iostream>
using namespace std;

int cnt[10], ret;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	for (char a : s) {
		cnt[a - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) continue;

		ret = max(ret, cnt[i]);
	}

	ret = max(ret, (cnt[6] + cnt[9] + 1) / 2);

	cout << ret;

	return 0;
}
