#include<iostream>
#include<vector>
using namespace std;

struct info {
	int w, v;
};
vector<info> backpack;

int n, k, w, v;
int dp[101][100001]; //저장되어야 할 값(가치)이 2개의 변수(물품의 수, 무게)에 의해 좌우된다

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		backpack.push_back({ w,v });
	}

	for (int idx = n - 1; idx >= 0; idx--) {
		for (int weight = k; weight >= 0; weight--) {
			dp[idx][weight] = dp[idx + 1][weight];

			if (weight + backpack[idx].w <= k) {
				dp[idx][weight] = max(dp[idx][weight], dp[idx + 1][weight + backpack[idx].w] + backpack[idx].v);
			}
		}
	}

	cout << dp[0][0];

	return 0;
}
