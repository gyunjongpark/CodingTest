#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

vector<string> v;
string s;
int n;

bool cmp(string a, string b) { //비내림차순
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

void check(string ret) {
	while (true) {
		if (ret.size() && ret[0] == '0') {
			ret.erase(0, 1); //erase(인덱스, 갯수)
		}
		else break; //size가 없거나(전부 0인 수를 모조리 지웠거나), 0이 아닌 숫자를 만났거나
	}

	if (ret.size() == 0) ret = "0"; //size가 없다면(0을 전부 지운 경우라면) 0 추가 후 v에 전달

	v.push_back(ret);

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> s;

		string ret = "";

		for (int i = 0; i < s.size(); i++) {
			if ('0' <= s[i] && s[i] <= '9') {
				ret += s[i];
			}
			else { //도중에 숫자가 아니라면
				if (ret.size()) { //중간 점검
					check(ret);

					ret = ""; //초기화
				}
			}
		}

		if (ret.size()) {
			check(ret); //마지막 요소가 숫자일 가능성. 최종 점검
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (string s : v) cout << s << '\n';

	return 0;
}
