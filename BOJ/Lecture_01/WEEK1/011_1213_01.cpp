#include<iostream>
using namespace std;

string s, ret;
char mid;
int flag, cnt[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	for (char a : s) {
		cnt[a]++; //cnt[65]~cnt[90]
	}

	for (int i = 'Z'; i >= 'A'; i--) { //90~65
		if (cnt[i] % 2) { //홀수라면
			mid = char(i); flag++;
			cnt[i]--;
		}
    
		if (flag == 2) break; //홀수가 2개 이상이면 break
    
		for (int j = 0; j < cnt[i]; j += 2) {
			ret += char(i);
			ret = char(i) + ret;
		}
	}

	//char mid
	if (mid) ret.insert(ret.begin() + ret.size() / 2, mid);

	if (flag == 2) cout << "I'm Sorry Hansoo";
	else cout << ret;

	return 0;
}
