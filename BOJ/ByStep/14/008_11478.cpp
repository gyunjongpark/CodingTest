#include<iostream>
#include<set>
using namespace std;

string s;
set<string> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	for (int i = 0; i < s.size(); i++) { //시작할 위치
		string str = "";

		for (int j = i; j < s.size(); j++) { //해당 위치부터 부분 문자열 생성
			str += s[j];
			st.insert(str);
		}
	}

	cout << st.size();

	return 0;
}
