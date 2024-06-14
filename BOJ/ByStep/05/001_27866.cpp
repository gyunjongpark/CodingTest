#include<iostream>
using namespace std;

string s;
int n;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s >> n;
	cout << s[n - 1];

	return 0;
}
