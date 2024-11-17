#include<iostream>
using namespace std;

string s;

bool isVowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> s) {
		if (s == "end") {
			break;
		}

		int v_cnt = 0, c_cnt = 0;
		bool isIncluded = false;
		bool flag = false;
		char prev = 0;

		for (char c : s) {
			if (isVowel(c)) {
				v_cnt++;
				c_cnt = 0;
				isIncluded = true;
			}
			else {
				v_cnt = 0;
				c_cnt++;
			}

			if (v_cnt == 3 || c_cnt == 3) flag = true; //조건 2

			if (prev == c && c != 'e' && c != 'o') flag = true; //조건 3

			prev = c;
		}

		if (!isIncluded) flag = true; //조건 1

		if (flag) cout << "<" << s << "> is not acceptable.\n";
		else cout << "<" << s << "> is acceptable.\n";
	}

	return 0;
}
