#include<iostream>
#include<list>
using namespace std;

list<char> L;
string s;
int n;
char ch, add;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s >> n;

	for (char c : s) {
		L.push_back(c);
	}

	list<char>::iterator cur = L.end();

	while (n--) {
		cin >> ch;

		if (ch == 'P') {
			cin >> add;
			L.insert(cur, add); //작업 후 cur는 다음 이터레이터를 반환합니다
		}
		else if (ch == 'L') {
			if (cur != L.begin()) {
				cur--;
			}
		}
		else if (ch == 'D') {
			if (cur != L.end()) {
				cur++;
			}
		}
		else if (ch == 'B') {
			if (cur != L.begin()) {
				cur--; //커서 '왼쪽'에 있는 문자를 삭제하기 위해
				cur = L.erase(cur); //작업 후 cur는 다음 이터레이터를 반환합니다
			}
		}
	}

	for (char c : L) {
		cout << c;
	}

	return 0;
}
