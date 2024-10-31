#include<iostream>
#include<climits> //INT_MAX
using namespace std;

int n, h, height, cnt;
int line[500001], s[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> h;

	//장애물 height는 h보다 작은 양수이다
	for (int i = 0; i < n; i++) {
		cin >> height; //장애물의 크기

		//첫 번째 장애물은 항상 석순이고, 그 다음에는 종유석과 석순이 번갈아가면서 등장한다
		if (i % 2 == 0) {
			line[0]++;
			line[height]--;
		}
		else { //종유석일 경우
			line[h - height]++;
		}
	}

	for (int i = 0; i < h; i++) {
		s[i + 1] = s[i] + line[i]; //s[1] ~ s[h]
	}

	int minVal = INT_MAX;

	for (int i = 1; i <= h; i++) {
		minVal = min(minVal, s[i]);
	}

	for (int i = 1; i <= h; i++) {
		if (s[i] == minVal) cnt++;
	}

	cout << minVal << ' ' << cnt;

	return 0;
}
