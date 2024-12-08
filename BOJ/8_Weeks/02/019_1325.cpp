#include<iostream>
#include<vector>
using namespace std;

vector<int> adj[10001];
bool visited[10001];
int n, m, a, b, v[10001];

int dfs(int here) {
	visited[here] = true;

	int ret = 1;

	for (int there : adj[here]) {
		if (!visited[there]) {
			ret += dfs(there);
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[b].push_back(a);
	}

	int ret = -1;

	for (int i = 1; i <= n; i++) {
		fill(&visited[0], &visited[0] + 10001, 0);

		v[i] = dfs(i);
		ret = max(ret, v[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (ret == v[i]) {
			cout << i << ' ';
		}
	}

	return 0;
}
