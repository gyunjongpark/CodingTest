/* 시간 초과 코드 (단순 재귀)
#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>> backpack;
int answer = -INF;
int n, w, k, v;

void recur(int idx, int weight, int value) {
    if (weight > k) return;
    if (idx == n) {
        answer = max(answer, value);
        return;
    }

    recur(idx + 1, weight + backpack[idx].first, value + backpack[idx].second);
    recur(idx + 1, weight, value);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        backpack.push_back({ w,v });
    }
    recur(0, 0, 0);

    cout << answer;

    return 0;
}
*/

#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>> backpack;
vector<vector<int>> dp;
int n, k, w, v;

int recur(int idx, int weight) {
	if (idx > n || weight > k) return -INF;
	if (idx == n) return 0;

	if (dp[idx][weight] != -1) return dp[idx][weight]; //이미 정의되었다면 그대로 반환(메모이제이션)

	//idx >= n이거나 weight > k일 때 recur(idx, weight)는 배열을 만들지 않고 값을 반환한다
	dp[idx][weight] = max(recur(idx + 1, weight), recur(idx + 1, weight + backpack[idx].first) + backpack[idx].second);

	return dp[idx][weight];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	//가치가 0일 수도 있으므로 -1로 초기화
	dp.resize(n, vector<int>(k + 1, -1));

	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		backpack.push_back({ w,v });
	}
	cout << recur(0, 0); //탑다운 dp
	
	return 0;
}
