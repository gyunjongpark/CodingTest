#include<iostream>
#include<string> //getline... string? cstring?
using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getline(cin, s);

	for (char a : s) {
		if ('A' <= a && a <= 'Z') {
			if (a + 13 > 'Z') a -= 13;
			else a += 13;
		}
		else if ('a' <= a && a <= 'z') {
			if (a + 13 > 'z') a -= 13;
			else a += 13;
		}
		cout << a;
	}

	return 0;
}
