#include<iostream>
using namespace std;

string alph = "abcdefghijklmnopqrstuvwxyz", s;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;

	for (int i = 0; i < 26; i++) {
		cout << (int)s.find(alph[i]) << ' ';
	}

	return 0;
}
