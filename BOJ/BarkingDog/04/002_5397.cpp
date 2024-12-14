#include<iostream>
#include<list>
using namespace std;

int t;
string s;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		list<char> L;
		list<char>::iterator cur = L.end();

		cin >> s;

		for (char c : s) {
			if (c == '<') {
				if (cur != L.begin()) {
					cur--;
				}
			}
			else if (c == '>') {
				if (cur != L.end()) {
					cur++;
				}
			}
			else if (c == '-') {
				if (cur != L.begin()) {
					cur--;
					cur = L.erase(cur); //작업 후 cur는 다음 이터레이터를 반환합니다
				}
			}
			else {
				L.insert(cur, c);
			}
		}

		for (char c : L) {
			cout << c;
		}

		cout << '\n';
	}

	return 0;
}
