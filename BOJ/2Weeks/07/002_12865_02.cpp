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

	for (int idx = 1; idx <= n; idx++) {
		for (int weight = 1; weight <= k; weight++) {
			dp[idx][weight] = dp[idx - 1][weight];

			if (weight - backpack[idx - 1].w >= 0) {
				dp[idx][weight] = max(dp[idx][weight], dp[idx - 1][weight - backpack[idx - 1].w] + backpack[idx - 1].v);
			}
		}
	}

	cout << dp[n][k];

	return 0;
}
