#include<iostream>
#include<string> /getline
using namespace std;

string s;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (getline(cin,s)) {
		cout << s << '\n';
	}

	return 0;
}
