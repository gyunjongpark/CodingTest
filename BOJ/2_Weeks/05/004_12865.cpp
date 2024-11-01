/* 재귀를 통한 로직 자체는 맞지만, 문제에서 주어진 시간 제한을 통과할 수 없어 오답인 코드
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

void recur(int idx, int weight, int value) {
	if (idx == n) {
		if (weight <= k) {
			ret = max(ret, value); //배낭이 버틸 수 있는 무게인 경우에만 최댓값을 갱신한다
		}

		return; //무게에 관계없이 n번째 idx라면 재귀 함수 종료
	}

	recur(idx + 1, weight + backpack[idx].w, value + backpack[idx].v);
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

	recur(0, 0, 0); //idx, weight, value

	cout << ret;

	return 0;
}
*/
