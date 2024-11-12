#include<iostream>
using namespace std;

int a, b, c, s, e, ret, cnt[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;

	for (int i = 0; i < 3; i++) {
		cin >> s >> e;

		for (int j = s; j < e; j++) {
			cnt[j]++;
		}
	}

	for (int i = 1; i <= 100; i++) {
		if (cnt[i] == 1) ret += cnt[i] * a;
		else if (cnt[i] == 2) ret += cnt[i] * b;
		else if (cnt[i] == 3) ret += cnt[i] * c;
	}

	cout << ret;

	return 0;
}
