#include<iostream>
#include<vector>
#define MAX 51
using namespace std;

int n, r, temp, root;
vector<int> adj[MAX];

int dfs(int here, int end) {
	int ret = 0;
	int child = 0;

	for (int there : adj[here]) {
		if (there == end) continue;
		else {
			ret += dfs(there, end);
			child++;
		}
		
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
	if (r == root) { //루트 노드르 지우면 0 반환
		cout << 0;
		return 0;
	}
	else { //루트 노드가 아닐 때 dfs 시작
		cout << dfs(root, r);
	}

	return 0;
}
