#include<iostream>
#include<algorithm> //sort, reverse
using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());

	cout << s;

	return 0;
}
