#include<iostream>
using namespace std;

string alph = "abcdefghijklmnopqrstuvwxyz", s;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;

	for (int i = 0; i < 26; i++) {
		//인덱스 반환. int로 형변환해야 string::npos = -1 반환
		cout << (int)s.find(alph[i]) << ' ';
	}

	return 0;
}
