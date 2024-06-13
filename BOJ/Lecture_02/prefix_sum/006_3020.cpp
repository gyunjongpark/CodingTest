#include<iostream>
#define MAX 500004

using namespace std;

int n, h, height, cnt;
int line[MAX], s[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> h;

	for (int i = 0; i < n; i++) {
		cin >> height; //장애물의 크기

		if (i % 2 == 0) { //석순일 경우
			line[0]++;
			if (height < h) {
				line[height]--;
			}
		}
		else{ //종유석일 경우
			if (h >= height) {
				line[h - height]++;
			}
		}
	}

	//height는 h보다 작은 양수
	for (int i = 0; i < h; i++) {
		s[i + 1] = s[i] + line[i];
	}

	int minVal = s[1];
	for (int i = 1; i <= h; i++) {
		minVal = min(minVal, s[i]);
	}

	int cnt = 0;
	for (int i = 1; i <= h; i++) {
		if (s[i] == minVal) cnt++;
	}
	cout << minVal << ' ' << cnt;

	return 0;
}
