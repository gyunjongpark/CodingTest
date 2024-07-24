#include<iostream>
using namespace std;

string alph = "abcdefghijklmnopqrstuvwxyz", s;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;

	for (int i = 0; i < 26; i++) {
		//인덱스 반환. string::npos = -1 반환을 위해 int로 형 변환 필요
		cout << (int)s.find(alph[i]) << ' ';
	}

	return 0;
}
