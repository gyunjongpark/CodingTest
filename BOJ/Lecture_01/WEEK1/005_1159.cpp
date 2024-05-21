#include<iostream>
using namespace std;

int n, cnt[26];
string s;
string ret = "";
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while(n--) {
		cin >> s;
		cnt[s[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 5) ret+=char(i + 97); //a=97
	}
	if (ret.size()) cout << ret;
	else cout<< "PREDAJA";

	return 0;
}
