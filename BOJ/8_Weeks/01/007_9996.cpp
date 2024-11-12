#include<iostream>
using namespace std;

string pattern, pre, post, s;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> pattern;

	//substr... 알파벳이 여러 개일 수 있다
	//find(찾는 문자) : 찾은 문자의 인덱스(배열 번호) 반환. 못 찾으면 string::npos 반환
	pre = pattern.substr(0, pattern.find("*")); //substr(시작 인덱스, 추출 갯수)
	post = pattern.substr(pattern.find("*") + 1);

	while (n--) {
		cin >> s;

		if (s.size() < pre.size() + post.size()) cout << "NE" << '\n';
		else {
			if (s.substr(0, pre.size()) == pre && s.substr(s.size() - post.size()) == post) {
				cout << "DA" << '\n';
			}
			else {
				cout << "NE" << '\n';
			}
		}
	}

	return 0;
}
