#include<iostream>
#include<cstring> //to_string...?
#include<string> //to_string...?
using namespace std;

string ret;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int title = 666; n > 0; title++) {
		string s = to_string(title);
		if (s.find("666") != string::npos) {
			ret = s;
			n--;
		}
	}
	cout << ret;

	return 0;
}
