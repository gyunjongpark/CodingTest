#include<iostream>
#include<list>
using namespace std;

list<char> s;
string str;
int n;
char ch, add;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;
	for (char c : str) s.push_back(c);

	list<char>::iterator cur = s.end();

	cin >> n;

	while (n--) {
		cin >> ch;
		
		if (ch == 'P') {
			cin >> add;
			s.insert(cur, add);
		}
		else if (ch == 'L') {
			if (cur != s.begin()) cur--;
		}
		else if (ch == 'D') {
			if (cur != s.end()) cur++;
		}
		else if (ch == 'B') {
			if (cur != s.begin()) {
				cur--;
				cur = s.erase(cur);
				//erase는 cur 다음 요소의 iter를 반환

			}
		}
	}
	for (char c : s) cout << c;

	return 0;
}
