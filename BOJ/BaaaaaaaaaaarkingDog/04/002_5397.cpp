#include<iostream>
#include<list>
using namespace std;

string input_str;
int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	while (n--) {
		cin >> input_str;

		list<char> L = {};

		list<char>::iterator cur = L.begin();

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
					cur = L.erase(cur); // 연산 이후 다음 이터레이터 반환
				}
			}
			else {
				L.insert(cur, c); // 연산 이후 다음 이터레이터 반환
			}
		}

		for (char c : L) cout << c;
		cout << '\n';
	}

	return 0;
}
