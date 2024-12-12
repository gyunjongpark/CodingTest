#include<iostream>
#include<vector>
using namespace std;

string s;
vector<string> str = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
int idx;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;

	for (int i = 0; i < str.size(); i++) {
		while (true) {
			idx = s.find(str[i]);

			if (idx == (int)string::npos) break;

			//replace(시작 위치, 바꿀 문자열의 범위, 대신 들어갈 문자열)
			s.replace(idx, str[i].size(), "#");
		}
	}

	cout << s.size();

	return 0;
}
