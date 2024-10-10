#include<iostream>
using namespace std;

int r, c, k, board[101][101], ret;
int pre_row, pre_col, cur_row, cur_col, bucket[101];

void update_row(int y) {
	fill(&bucket[0], &bucket[0] + 101, 0);

	for (int x = 1; x <= pre_col; x++) {
		bucket[board[y][x]]++;
	}

	int size = 0;

	//횟수, 값을 기준으로 오름차순
	for (int i = 1; i <= 100; i++) { //1. 횟수
		for (int j = 1; j <= 100; j++) { //2. 값
			if (bucket[j] == i) {
				board[y][++size] = j;
				board[y][++size] = i;

				if (size == 100) break;
			}
		}

		if (size == 100) break;
	}

	//기존의 길이보다 짧게 갱신되었을 때 남은 칸을 0으로 저장
	for (int x = size + 1; x <= pre_col; x++) {
		board[y][x] = 0;
	}

	if (cur_col < size) {
		cur_col = size; //size를 cur로 갱신
	}

	return;
}

void update_col(int x) {
	fill(&bucket[0], &bucket[0] + 101, 0);

	for (int y = 1; y <= pre_row; y++) {
		bucket[board[y][x]]++;
	}

	int size = 0;

	//횟수, 값을 기준으로 오름차순
	for (int i = 1; i <= 100; i++) { //1. 횟수
		for (int j = 1; j <= 100; j++) { //2. 값
			if (bucket[j] == i) {
				board[++size][x] = j;
				board[++size][x] = i;

				if (size == 100) break;
			}
		}

		if (size == 100) break;
	}

	//기존의 길이보다 짧게 갱신되었을 때 남은 칸을 0으로 저장
	for (int y = size + 1; y <= pre_row; y++) {
		board[y][x] = 0;
	}

	if (cur_row < size) {
		cur_row = size; //size를 cur로 갱신
	}

	return;
}

void go() {	
	while (board[r][c] != k) {
		if (cur_row >= cur_col) {
			pre_col = cur_col; //0을 채우기 위한 pre
			cur_col = 0;

			for (int y = 1; y <= cur_row; y++) {
				update_row(y);
			}
		}
		else {
			pre_row = cur_row; //0을 채우기 위한 pre
			cur_row = 0;

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
			cin >> board[i][j];
		}
	}

	cur_row = 3;
	cur_col = 3;

	go();

	if (ret > 100) cout << -1;
	else cout << ret;

	return 0;
}
