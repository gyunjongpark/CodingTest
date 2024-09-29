#include<iostream>
using namespace std;

string s;
int cnt[26], ret, temp;
int maxVal = -1;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;

	for (char a : s) {
		if (a >= 'a') a -= 32; //'a' = 97, 'A' = 65

		cnt[a - 'A']++; //cnt[0~25]
	}

	for (int i : cnt) {
		maxVal = max(maxVal, i);
	}

	for (int cur = 0; cur < 26; cur++) { //alphabet search
		if (cnt[cur] == maxVal) {
			ret++;
			temp = cur;
		}
	}
	
	if (ret == 1) cout << (char)(temp + 65); //숫자를 대문자로
	else cout << '?';

	return 0;
}
