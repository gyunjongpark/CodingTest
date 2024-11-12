#include<iostream>
#include<string> //getline
using namespace std;

string s, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getline(cin, s);

	for (char c : s) {
		if ('a' <= c && c <= 'z') {
			if (c + 13 > 'z') c -= 13;
			else c += 13;
		}
		else if ('A' <= c && c <= 'Z') {
			if (c + 13 > 'Z') c -= 13;
			else c += 13;
		}
    
		ret += c;
	}
  
	cout << ret;

	return 0;
}
