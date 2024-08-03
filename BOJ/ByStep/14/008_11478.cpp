#include<iostream>
#include<set>
using namespace std;

string s, str;
set<string> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		for (int j = i; j < s.size(); j++) {
			str += s[j];
			st.insert(str); //집합 : insert = 벡터 : push_back
		}
		str = ""; //init
	}
	cout << st.size();

	return 0;
}
