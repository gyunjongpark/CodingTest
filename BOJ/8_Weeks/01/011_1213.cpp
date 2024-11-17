#include<iostream>
using namespace std;

string s, ret;
string mid = -1;
int flag, cnt['Z' + 1];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	for (char c : s) {
		cnt[c]++;
	}

	for (int i = 'Z'; i >= 'A'; i--) {
		if (cnt[i] % 2) {
			mid = (char)i;
			flag++;
			cnt[i]--;
		}

		if (flag == 2) break; //mid는 1개가 최대

		for (int j = 0; j < cnt[i]; j += 2) { //양쪽으로 하나씩 덧붙인다
			ret += (char)i;
			ret = (char)i + ret;
		}
	}

	if (mid != -1) {
		ret.insert(ret.size() / 2, mid); //insert(위치, 문자열)
	}

	if (flag == 2) {
		cout << "I'm Sorry Hansoo";
	}
	else {
		cout << ret;
	}

	return 0;
}
