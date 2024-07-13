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
		else { //그룹 단어가 아닌 것을 찾는다
			for (int j = 0; j < s.size(); j++) {
				if (s[j] != s[j + 1]) {

					//find(찾는 요소,시작 위치)
					if (s.find(s[j], j + 2) != string::npos) { //같은 단어를 찾았다면 그룹 단어가 아니다
						cnt++; //그룹 단어가 아니라면 cnt++
						break;
					}
				}
			}
		}
	}

	//전체 단어 - 그룹 단어가 아닌 단어
	cout << t - cnt;

	return 0;
}
