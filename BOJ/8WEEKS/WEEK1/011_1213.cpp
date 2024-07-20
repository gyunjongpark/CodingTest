#include<iostream>
using namespace std;

int flag, cnt['Z' + 1];
string s, ret;
char mid; // string mid도 가능하다

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
		if (flag == 2) break; // mid는 1 이하

		for (int j = 0; j < cnt[i]; j += 2) {
			ret += (char)i;
			ret = (char)i + ret;
		}
  	}
	
	// mid의 타입이 string이라면
	// if (mid.size()) ret.insert(ret.size() / 2, mid);
  
	if (mid) ret.insert(ret.begin() + ret.size() / 2, mid);
	
	if (flag == 2) cout << "I'm Sorry Hansoo";
	else cout << ret;
	
	return 0;
}
