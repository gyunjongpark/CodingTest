#include<iostream>
using namespace std;

int n, ret;
string s;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		ret += s[i] - 48; //문자 - 숫자 = 48
	}
	cout << ret;
  
	return 0;
}
