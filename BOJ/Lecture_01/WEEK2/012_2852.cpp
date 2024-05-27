#include<iostream>
#include<string> //to_string...?
#include<cstring> //to_string...?
using namespace std;

int n, asum, bsum, A, B, team;
string t, pre;

string print(int sum) {
	string d = "00" + to_string(sum / 60);
	string e = "00" + to_string(sum % 60);

	return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}

int string_to_int(string s) {
	return atoi((s.substr(0, 2)).c_str()) * 60 + atoi((s.substr(3, 2)).c_str());
}

void go(int& sum, string t, string pre) {
	sum += string_to_int(t) - string_to_int(pre);

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> team >> t;

		if (A > B) go(asum, t, pre);
		else if (A < B) go(bsum, t, pre);

		team == 1 ? A++ : B++; //초기 설정
		pre = t; //초기 설정
	}
	if (A > B) go(asum, "48:00", pre);
	else if (A < B) go(bsum, "48:00", pre);
	
	cout << print(asum) << '\n';
	cout << print(bsum) << '\n';

	return 0;
}
