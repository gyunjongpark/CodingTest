#include<iostream>
#include<list>
using namespace std;

string str; //input
int n; //number

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> str;

		list<char> s = {};
		list<char>::iterator cur = s.begin();

		for (char c : str) {
			if (c == '<') {
				if (cur != s.begin()) {
					cur--;
				}
			}
			else if (c == '>') {
				if (cur != s.end()) {
					cur++;
				}
			}
			else if (c == '-') {
				if (cur != s.begin()) {
					cur--;
					cur = s.erase(cur); //erase
				}
			}
			else {
				s.insert(cur, c); //insert
			}
		}

		for (char c : s) cout << c;
		cout << '\n';
	}

	return 0;
}
