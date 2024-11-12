#include<iostream>
#include<algorithm> //reverse
using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	
	string ret = s;
  
	reverse(s.begin(), s.end());

	if (ret == s) cout << 1;
	else cout << 0;

	return 0;
}
