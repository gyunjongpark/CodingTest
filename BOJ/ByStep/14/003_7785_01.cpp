#include<iostream>
#include<algorithm> //sort
#include<vector>
#include<map>
using namespace std;

map<string, string> mp;
vector<string> v;
string a, b;
int n;

bool cmp(string a, string b) {
	return a > b; //사전의 역순
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		mp[a] = b;
	}

	for (pair<string, string> s : mp) {
		if (s.second == "enter") {
			v.push_back(s.first);
		}
	}
	
	sort(v.begin(), v.end(), cmp);

	for (string s : v) cout << s << '\n';

	return 0;
}
