#include<iostream>
using namespace std;

string s, mid, ret;
int cnt[26], flag;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	for (char c : s) {
		cnt[c - 'A']++;
	}

	for (char i = 'Z'; i >= 'A'; i--) {
		if (cnt[i - 'A'] % 2) {
			mid = i;
			flag++;
			cnt[i - 'A']--;
		}

		if (flag >= 2) break;

		for (int j = 0; j < cnt[i - 'A']; j += 2) {
			ret += i;
			ret = i + ret;
		}
	}

	if (mid.size()) {
		ret.insert(ret.size() / 2, mid); //string.insert(위치(인덱스), 문자열)
	}

	if (flag >= 2) {
		cout << "I'm Sorry Hansoo";
	}
	else {
		cout << ret;
	}

	return 0;
}
