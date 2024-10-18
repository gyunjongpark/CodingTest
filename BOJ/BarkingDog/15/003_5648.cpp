#include<iostream>
#include<algorithm> //sort
#include<vector>
using namespace std;

int n;
string a[1000001];

bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
    
		reverse(a[i].begin(), a[i].end());

		while (*a[i].begin() == '0') {
			a[i].erase(0, 1);
		}
	}

	sort(a, a + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << a[i] << '\n';
	}

	return 0;
}
