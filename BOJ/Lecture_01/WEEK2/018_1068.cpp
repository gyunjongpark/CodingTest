#include<iostream>
#include<vector>
#define MAX 51
using namespace std;

bool visited[MAX];
vector<int> adj[MAX];
int n, r, temp, root, ret;

int dfs(int here) {
	visited[here] = 1;
	int ret = 0; //최종적인 리프 노드의 개수 반환
	int child = 0; //리프 노드를 판별하는 자식 노드의 개수

	for (int there : adj[here]) {
		if (there == r) continue; //지울 노드라면 계산 건너뛰기

		if (!visited[there]) {
			ret+=dfs(there);
			child++;
		}
	}
	if (!child) return 1; //자식 노드가 없다면 리프 노드

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) { //노드 번호
		cin >> temp;
		if (temp == -1) root = i; //루트 노드
		else {
			adj[temp].push_back(i); //연결리스트로 부모-자식 노드 구현
		}
	}

	cin >> r; //지울 노드
	if (r == root) { //지울 노드가 루트 노드라면
		cout << 0;
		return 0;
	}
	else {
		cout << dfs(root); //루트 노드부터 탐색 시작
	}
	
	return 0;
}
