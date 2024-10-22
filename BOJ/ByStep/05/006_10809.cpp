#include<iostream>
using namespace std;

string alph = "abcdefghijklmnopqrstuvwxyz", s;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;

	for (int i = 0; i < 26; i++) {
		//find(문자열, 찾는 위치) : 해당 위치의 인덱스 반환, 못찾으면 string::npos 반환
		//string::npos는 size_t 타입(64비트 OS에서 8바이트)의 최대값 = unsigned long long의 최대값을 반환하므로 (int)로 형변환 시 -1을 반환한다
		cout << (int)s.find(alph[i]) << ' ';
	}

	return 0;
}
