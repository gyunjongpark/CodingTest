#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int l, c;
char a[16];

bool check(vector<char>& v) {
	int v_cnt = 0;
	int c_cnt = 0;

	for (char c : v) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') v_cnt++;
		else c_cnt++;
	}

	if (v_cnt >= 1 && c_cnt >= 2) return true;
	else return false;
}

void print(vector<char>& v) {
	for (char c : v) {
		cout << c;
	}

	cout << '\n';

	return;
}

void combi(int start, vector<char>& v, vector<bool>& visited) {
	if (v.size() == l) {
		if (check(v)) {
			print(v);
		}
		
		return;
	}

	for (int i = start + 1; i < c; i++) {
		if (visited[a[i] - 'a']) continue;

		v.push_back(a[i]);
		visited[a[i] - 'a'] = true;

		combi(i, v, visited);

		v.pop_back();
		visited[a[i] - 'a'] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		cin >> a[i];
	}

	sort(a, a + c);

	vector<char> v;
	vector<bool> visited(26, false);

	combi(-1, v, visited);

	return 0;
}
