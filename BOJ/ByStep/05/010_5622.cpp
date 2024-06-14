#include<iostream>
using namespace std;

string s;
string alphabet = "22233344455566677778889999";
int ret;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		ret += alphabet[s[i] - 65] - 48; //'A' = 65, 문자 - 숫자 = 48
		ret++; //한 칸 옆의 숫자
	}
	cout << ret;

	return 0;
}
