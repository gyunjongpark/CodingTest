#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int n, m, a[10];
vector<int> v;
vector<bool> visited(10001, false); //입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다

void print(vector<int> v) {
	for (int i : v) cout << i << ' '; cout << '\n';
	return;
}

void combi(int start, vector<int>& v, vector<bool>& visited) {
	if (v.size() == m) {
		print(v);
		return;
	}

	for (int i = start + 1; i < n; i++) {
		if (visited[a[i]]) continue;

		v.push_back(a[i]);
		visited[a[i]] = true;

		combi(start, v, visited);

		v.pop_back();
		visited[a[i]] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	combi(-1, v, visited);

	return 0;
}
