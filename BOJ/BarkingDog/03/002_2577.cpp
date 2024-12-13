#include<iostream>
#include<string> //to_string
using namespace std;

int a, b, c, ret, cnt[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;
	ret = a * b * c; //10억 미만의 수이므로 int 자료형에 담을 수 있다
	string str = to_string(ret);

	for (char c : str) {
		cnt[c - '0']++;
	}

	for (int i : cnt) {
		cout << i << '\n';
	}

	return 0;
}
