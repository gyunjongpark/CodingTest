#include<iostream>
#include<algorithm>
using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	sort(s.begin(), s.end(), greater<int>());

	cout << s;

	return 0;
}
