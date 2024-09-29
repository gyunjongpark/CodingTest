#include<iostream>
#include<algorithm> //sort
#include<vector>
using namespace std;

vector<pair<int, int>> v;
int n, x, y;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> x >> y;
		
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end(), cmp);

	for (pair<int, int> i : v) {
		cout << i.first << ' ' << i.second << '\n';
	}

	return 0;
}
