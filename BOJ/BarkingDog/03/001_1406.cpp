#include<iostream>
#include<list>
using namespace std;

list<char> lst;
string input_str;
char ch, add;
int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> input_str >> n;

	for (char c : input_str) {
		lst.push_back(c);
	}

	list<char>::iterator cur = lst.end();

	while (n--) {
		cin >> ch;

		if (ch == 'P') {
			cin >> add;
			lst.insert(cur, add); //다음 이터레이터를 반환
		}
		else if (ch == 'L') {
			if (cur != lst.begin()) {
				cur--;
			}
		}
		else if (ch == 'D') {
			if (cur != lst.end()) {
				cur++;
			}
		}
		else if (ch == 'B') {
			if (cur != lst.begin()) {
				cur--; //커서 '왼쪽'에 있는 문자를 삭제함
				cur = lst.erase(cur); //다음 이터레이터를 반환
			}
		}
	}

	for (char c : lst) cout << c;

	return 0;
}
