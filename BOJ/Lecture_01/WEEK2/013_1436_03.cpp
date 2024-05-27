#include<iostream>
#include<cstring> //to_string...?
#include<string> //to_string...?
using namespace std;

int cnt, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int i = 666;
	while (true) {
		string ret = to_string(i);

		if (ret.find("666") != string::npos) {
			cnt++;
			if (cnt == n) {
				cout << ret;
				break;
			}
		}
		i++;
	}
	
	return 0;
}
