#include<iostream>
#include<vector>
#define MAX 10001
using namespace std;

bool visited[MAX];
vector<int> adj[MAX];
int n, m, a, b, dp[MAX];

int dfs(int here) {
	visited[here] = 1;
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

	int maxVal = -1;
	for (int i = 1; i <= n; i++) {
		fill(&visited[0], &visited[0] + MAX, 0);
		dp[i] = dfs(i);
		maxVal = max(maxVal, dp[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (dp[i] == maxVal) cout << i << ' ';
	}
	
	return 0;
}
