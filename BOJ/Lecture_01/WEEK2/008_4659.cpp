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
		if (s == "end") break;

		int vcnt = 0, ccnt = 0;
		bool isIncludeVowel = 0;
		bool flag = 0;
		char pre = 0; //null

		for(int i=0;i<s.size();i++) {
			if (isVowel(s[i])) {
				vcnt++;
				ccnt = 0;
				isIncludeVowel = 1;
			}
			else {
				ccnt++;
				vcnt = 0;
			}
			if (vcnt == 3 || ccnt == 3) flag = 1; //2번 조건
			if (i >= 1 && pre == s[i] && s[i] != 'e' && s[i] != 'o') flag = 1; //3번 조건
			pre = s[i]; //3번 조건. 이전 문자와 비교
		}
		if (!isIncludeVowel) flag = 1; //1번 조건

		if (flag) cout << "<" << s << "> is not acceptable.\n";
		else cout << "<" << s << "> is acceptable.\n";
	}

	return 0;
}
