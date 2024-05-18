#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, a;
string b;
vector<pair<int, string>> v;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	
	stable_sort(v.begin(), v.end(), cmp);

	for (pair<int, string> a : v) {
		cout << a.first << ' ' << a.second << '\n';
	}

	return 0;
}
