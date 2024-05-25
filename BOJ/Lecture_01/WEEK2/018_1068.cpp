#include<iostream>
#include<vector>
#define MAX 51
using namespace std;

int n, temp, root, r;
vector<int> adj[MAX];

int dfs(int here, int limit) {
	int ret = 0;
	int child = 0;

	for (int there : adj[here]) {
		if (there == limit) continue;

		ret += dfs(there, limit);
		child++;
	}
	if (!child) return 1;

	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == -1) root = i;
		else {
			adj[temp].push_back(i);
		}
	}

	cin >> r;
	if (r == root) {
		cout << 0;
		return 0;
	}
	else {
		cout << dfs(root, r);
	}
	
	return 0;
}
