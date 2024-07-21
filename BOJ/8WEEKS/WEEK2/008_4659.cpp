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

		int vcnt = 0, ccnt = 0; // init
		bool isIncludeV = 0; // init
		bool flag = 0; // init

		for (char c : s) {
			if (isVowel(c)) {
				vcnt++;
				ccnt = 0;
				isIncludeV = true;
			}
			else {
				vcnt = 0;
				ccnt++;
			}

			if (vcnt == 3 || ccnt == 3) flag = 1; // 조건 2

      char prev = 0; // init
			if (prev == c && c != 'e' && c != 'o') flag = 1; // 조건 3
      
			prev = c;
		}

		if (!isIncludeV) flag = 1; //  조건 1

		if (flag) cout << "<" << s << "> is not acceptable."<<'\n';
    else cout << "<" << s << "> is acceptable."<<'\n';		
	}

	return 0;
}
