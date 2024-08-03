#include<iostream>
#include<string> //to_string
using namespace std;

int cnt, n;
string ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 666; cnt < n; i++) {
		ret = to_string(i);
		if (ret.find("666") != string::npos) {
			cnt++;
		}
	}
	cout << ret;
	
	return 0;
}
