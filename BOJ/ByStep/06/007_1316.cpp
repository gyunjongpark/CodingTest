#include<iostream>
using namespace std;

string s;
int t, cnt;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> s;

		if (s.size() <= 2) continue; //무조건 그룹 단어
		else {
			for (int j = 0; j < s.size(); j++) {
				if (s[j] != s[j + 1]) {
					if (s.find(s[j], j + 2) != string::npos) { //같은 단어를 찾았다면 그룹 단어가 아니다
						cnt++;
						break;
					}
				}
			}
		}
	}
	
	cout << t - cnt; //전체 단어 - 그룹 단어가 아닌 단어 = 그룹 단어

	return 0;
}
