#include<iostream>
using namespace std;

int n;
string s;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		cout << s[0] << s[s.size() - 1] << '\n';
	}

	return 0;
}
