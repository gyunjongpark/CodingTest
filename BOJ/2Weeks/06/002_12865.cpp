#include<iostream>
#include<vector>
#include<climits> //INT_MIN
using namespace std;

struct info {
	int w, v;
};
vector<info> backpack;

int n, k, w, v;
int ret = INT_MIN;
int dp[101][100001]; //저장되어야 할 값(가치)이 2개의 변수(물품의 수, 무게)에 의해 좌우된다

int recur(int idx, int weight) {
	if (idx > n || weight > k) return INT_MIN;
	if (idx == n) return 0;

	if (dp[idx][weight]) return dp[idx][weight]; //1 ≤ K ≤ 100,000

	dp[idx][weight] = max(recur(idx + 1, weight + backpack[idx].w) + backpack[idx].v, recur(idx + 1, weight));

	return dp[idx][weight];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		backpack.push_back({ w,v });
	}

	cout << recur(0, 0);

	return 0;
}
