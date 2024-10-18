#include<iostream>
using namespace std;

int n, m, k, r, c, ret;
int note[42][42], paper[12][12];

void rotate() {
	int temp[12][12];

	for (int i = 0; i < c; i++) { //temp를 기준으로 r, c 반복문 진행
		for (int j = 0; j < r; j++) {
			temp[i][j] = paper[r - j - 1][i];
		}
	}

	fill(&paper[0][0], &paper[0][0] + 12 * 12, 0);

	for (int i = 0; i < c; i++) { //temp를 기준으로 r, c 반복문 진행
		for (int j = 0; j < r; j++) {
			paper[i][j] = temp[i][j];
		}
	}

	//열과 행이 바뀐 temp가 새로운 paper가 되므로 다음 rotate는 r과 c가 바뀐다
	swap(r, c); //call by reference

	return;
}

//R x C 사이즈의 스티커가 좌상단 (y,x) 기준으로 온전히 붙여지는가?
bool postable(int y, int x) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			//paper가 1인데 이미 note가 1이라면(하나라도 겹친다면) 붙일 수 없다
			if (note[y + i][x + j] == 1 && paper[i][j] == 1) {
				return false;
			}
		}
	}

	return true; //위 반복문을 통과했다면 스티커를 붙일 수 있는 상황이므로 true 반환
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	while (k--) {
		cin >> r >> c;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> paper[i][j];
			}
		}

		for (int dir = 0; dir < 4; dir++) {
			bool is_posted = false;

			for (int y = 0; y <= n - r; y++) {
				if (is_posted) break;

				for (int x = 0; x <= m - c; x++) {
					if (postable(y, x)) { //붙일 수 있는지 검사

						//검사 통과! R x C 사이즈의 스티커 붙이기
						for (int i = 0; i < r; i++) {
							for (int j = 0; j < c; j++) {
								if (paper[i][j] == 1) {
									note[y + i][x + j] = 1;
								}
							}
						}

						is_posted = true;

						break;
					}
				}
			}

			if (is_posted) break;

			rotate();
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ret += note[i][j];
		}
	}

	cout << ret;

	return 0;
}
