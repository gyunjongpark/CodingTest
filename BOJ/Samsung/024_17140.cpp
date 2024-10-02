#include<iostream>
using namespace std;

int r, c, k, a[101][101], ret;
int pre_col, cur_col, pre_row, cur_row;

void update_row(int y) {
	int bucket[101];
	fill(&bucket[0], &bucket[0] + 101, 0);

	for (int x = 1; x <= pre_col; x++) {
		bucket[a[y][x]]++;
	}

	int size = 0;

	//횟수, 값을 기준으로 오름차순
	for (int i = 1; i <= 100; i++) { //1. 횟수
		for (int j = 1; j <= 100; j++) { //2. 값
			if (bucket[j] == i) {
				a[y][++size] = j;
				a[y][++size] = i;

				if (size == 100) break;
			}
		}

		if (size == 100) break;
	}

  //기존의 길이보다 짧게 갱신되었을 때 남은 칸을 0으로 저장
  //기존의 길이에서 추가되는 길이는 자동으로 0이므로 저장할 필요 없음
	for (int x = size + 1; x <= pre_col; x++) {
		a[y][x] = 0;
	}

	if (cur_col < size) {
		cur_col = size;
	}

	return;
}

void update_col(int x) {
	int bucket[101];
	fill(&bucket[0], &bucket[0] + 101, 0);

	for (int y = 1; y <= pre_row; y++) {
		bucket[a[y][x]]++;
	}

	int size = 0;

	//횟수, 값을 기준으로 오름차순
	for (int i = 1; i <= 100; i++) { //1. 횟수
		for (int j = 1; j <= 100; j++) { //2. 값
			if (bucket[j] == i) {
				a[++size][x] = j;
				a[++size][x] = i;

				if (size == 100) break;
			}
		}

		if (size == 100) break;
	}

  //기존의 길이보다 짧게 갱신되었을 때 남은 칸을 0으로 저장
  //기존의 길이에서 추가되는 길이는 자동으로 0이므로 저장할 필요 없음
	for (int y = size + 1; y <= pre_row; y++) {
		a[y][x] = 0;
	}

	if (cur_row < size) {
		cur_row = size;
	}

	return;
}

void go() {
	while (a[r][c] != k) {
		if (cur_row >= cur_col) {
			pre_col = cur_col; //행 갯수 옮기기
			cur_col = 0; //init

			for (int y = 1; y <= cur_row; y++) {
				update_row(y);
			}
		}
		else {
			pre_row = cur_row; //열 갯수 옮기기
			cur_row = 0; //init

			for (int x = 1; x <= cur_col; x++) {
				update_col(x);
			}
		}

		ret++;

		if (ret > 100) break;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}

	//행 갯수 3, 열 갯수 3으로 시작한다
	cur_row = 3, cur_col = 3;

	go();

	if (ret > 100) cout << -1;
	else cout << ret;

	return 0;
}
