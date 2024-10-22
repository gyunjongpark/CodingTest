#include<iostream>
#include<string> //getline
using namespace std;

string s;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	getline(cin, s);

	int cnt = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ')cnt++;
	}

	if (s[0] == ' ') cnt--;
	if (s[s.size() - 1] == ' ') cnt--;

	cout << cnt + 1;

	return 0;
}
