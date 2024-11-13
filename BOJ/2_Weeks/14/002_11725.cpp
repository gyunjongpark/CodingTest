#include<iostream>
#include<vector>
using namespace std;

int n, a, b, parent[100001];
bool visited[100001];
vector<int> node[100001];

void dfs(int here) {
	visited[here] = true;

	for (int i = 0; i < node[here].size(); i++) {
		int next = node[here][i];

		if (!visited[next]) {
			parent[next] = here;
			dfs(next);
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
    
		node[a].push_back(b);
		node[b].push_back(a);
	}

	dfs(1); //root = 1

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}
