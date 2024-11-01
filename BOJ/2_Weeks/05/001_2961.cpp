#include<iostream>
#include<climits> //INT_MAX
using namespace std;

int n, s[11], b[11];
int ret = INT_MAX;

void recur(int idx, int sour, int bitter, int used) {
	if (idx == n) {
		if (used > 0) {
			ret = min(ret, abs(sour - bitter)); //재료를 사용한 경우에만 최솟값을 갱신한다
		}

		return; //재료 사용 여부에 관계없이 n번째 idx라면 재귀 함수 종료
	}

	recur(idx + 1, sour * s[idx], bitter + b[idx], used + 1);
	recur(idx + 1, sour, bitter, used);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i] >> b[i];
	}

	recur(0, 1, 0, 0);

	cout << ret;

	return 0;
}
