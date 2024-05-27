#include<iostream>
#include<vector>
#define MAX 10001
using namespace std;

bool visited[MAX];
vector<int> adj[MAX];
int n, m, a, b, dp[MAX];

int dfs(int here) {
	visited[here] = 1;
	int ret = 1; //방문했다면 해킹한 컴퓨터 1대 증가!

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
		adj[b].push_back(a); //연결리스트로 해킹 관계 구현
	}

	int maxVal = -1; //100000보다 작거나 같은 자연수
	for (int i = 1; i <= n; i++) { //전체 컴퓨터 탐색
		fill(&visited[0], &visited[0] + MAX, 0);
		dp[i] = dfs(i); //번호마다 dfs 탐색 후 가짓수를 배열에 저장
		maxVal = max(maxVal, dp[i]); //가장 많은 가짓수 maxVal에 저장
	}

	for (int i = 1; i <= n; i++) { //maxVal과 일치하는 컴퓨터 오름차순으로 출력
		if (dp[i] == maxVal) cout << i << ' ';
	}
	
	return 0;
}
