#include<iostream>
using namespace std;

string s;
int b, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> s >> b;

	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			ret = ret * b + (s[i] - 48);
		}
		else ret = ret * b + (s[i] - 55);
	}

	cout << ret;

	return 0;
}
