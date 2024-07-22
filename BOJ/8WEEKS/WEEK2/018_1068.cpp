#include<iostream>
#include<vector>
using namespace std;

vector<int> adj[51]; // push_back
bool visited[51];
int n, r, temp, root, ret;

int dfs(int here) {
	visited[here] = 1;

	int ret = 0; // 리프 노드의 수 init
	int child = 0; // 자식 노드의 수 init

	for (int there : adj[here]) {
		if (there == r) continue;

		if (!visited[there]) {
			ret += dfs(there);
			child++;
		}
	}
	
	if (!child) ret++; // 리프 노드라면 ret++

	return ret; // 각 dfs에 대하여 0(자식 노드가 있을 때) 또는 1(리프 노드) 중 하나를 반환
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) { // 0번 노드부터 입력
		cin >> temp;

		if (temp == -1) {
      			root = i;
   		}
		else {
			adj[temp].push_back(i);
		}
	}

	cin >> r;
  
	if (r == root) {
		cout << 0;
	}
	else {
		cout << dfs(root); // 루트 노드부터 탐색
	}

	return 0;
}
