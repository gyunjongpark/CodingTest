#include<iostream>
#include<list>
using namespace std;

string input_str;
int t;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		list<char> L;
		list<char>::iterator cur = L.end();

		cin >> input_str;

		for (char c : input_str) {
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
					cur = L.erase(cur); //해당 이터레이터에 값을 삭제 후 다음 이터레이터를 가리킨다
				}
			}
			else {
				L.insert(cur, c); //해당 이터레이터에 값을 삽입 후 다음 이터레이터를 가리킨다
			}
		}

		for (char c : L) cout << c;

		cout << '\n';
	}

	return 0;
}
