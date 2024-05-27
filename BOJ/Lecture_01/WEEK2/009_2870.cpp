#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> v;
int n;
string s, ret;

bool cmp(string a, string b) { //비내림차순
	if (a.size() == b.size()) return a < b;

	return a.size() < b.size();
}

void check() {
	while (true) {
		if (ret.size() && ret[0] == '0') ret.erase(0,1); //erase(배열 번호,갯수)
		else break; //size가 없거나(0을 전부 지우거나), 0이 아닌 숫자거나
	}

	if (ret.size() == 0) ret = "0"; //size가 없다면(0을 전부 지웠다면) ret=0
	v.push_back(ret); //ret=0이 아닌 숫자
	ret = ""; //ret 초기화

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> s;
		ret = "";
		for (int i = 0; i < s.size(); i++) {
			if ('0' <= s[i] && s[i] <= '9') {
				ret += s[i];
			}
			else if (ret.size()) { //숫자가 도중에 끊기면 check. 중간 점검
				check();
			}
		}
		if (ret.size()) check(); //마지막 요소가 숫자일 가능성 check. 최종 점검
	}

	sort(v.begin(), v.end(), cmp);

	for (string s : v) cout << s << '\n';

	return 0;
}
