#include<iostream>
using namespace std;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
int n, m, d, s, board[49][49], ret;
int line[2500], line_idx;

void blizzard(int d, int s) {
	int cy = n / 2;
	int cx = n / 2;

	for (int i = 1; i <= s; i++) {
		int ny = cy + (dy[d] * i);
		int nx = cx + (dx[d] * i);

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

		board[ny][nx] = 0;
	}

	return;
}

void push_blank_and_convert_to_line() {
	line_idx = 0; //init

	int tornado_dy[] = { 0,1,0,-1 };
	int tornado_dx[] = { -1,0,1,0 };

	int cy = n / 2;
	int cx = n / 2;
	int d = 0; //왼쪽 방향부터 토네이도 시작
	int loop_cnt = 2; //방향이 2번 변할 때마다 방향의 길이 증가
	
	for (int dist = 1; dist < n; dist++) {
		if (dist == n - 1) loop_cnt = 3; //마지막은 3번으로 바꿔 배열 완성하기

		for (int i = 0; i < loop_cnt; i++) {
			for (int j = 0; j < dist; j++) {
				cy += tornado_dy[d];
				cx += tornado_dx[d];

				if (board[cy][cx] != 0) {
					line[line_idx++] = board[cy][cx];
				}
			}

			d = (d + 1) % 4;
		}
	}

	return;
}

int explode_and_get_point() {
	int point = 0;
	int same_cnt = 1; //본인을 포함시켜 계산하므로 1부터 시작

	for (int i = 1; i < line_idx; i++) {
		if (line[i] == line[i - 1]) {
			same_cnt++;
		}
		else {
			if (same_cnt >= 4) {
				for (int j = 0; j < same_cnt; j++) {
					point += line[i - j - 1];
					line[i - j - 1] = 0;
				}
			}

			same_cnt = 1;
		}
	}

	if (same_cnt >= 4) {
		for (int j = 0; j < same_cnt; j++) {
			point += line[line_idx - j - 1];
			line[line_idx - j - 1] = 0;
		}
	}

	ret += point;

	return point;
}

void push_blank() {
	int temp_line[2500] = { 0, };
	int temp_idx = 0;

	for (int i = 0; i < line_idx; i++) {
		if (line[i] != 0) {
			temp_line[temp_idx++] = line[i];
		}
	}

	for (int i = 0; i < temp_idx; i++) {
		line[i] = temp_line[i];
	}

	for (int i = temp_idx; i < line_idx; i++) {
		line[i] = 0;
	}

	line_idx = temp_idx;

	return;
}

void change() {
	int temp_line[2500] = { 0, };
	int temp_idx = 0;

	int same_cnt = 1;

	for (int i = 1; i < line_idx; i++) {
		if (line[i - 1] == line[i]) {
			same_cnt++;
		}
		else {
			if (temp_idx < n * n - 2) {
				temp_line[temp_idx++] = same_cnt;
				temp_line[temp_idx++] = line[i - 1];
			}

			same_cnt = 1;
		}
	}

	if (line_idx > 0 && temp_idx < n * n - 2) {
		temp_line[temp_idx++] = same_cnt;
		temp_line[temp_idx++] = line[line_idx - 1];
	}

	for (int i = 0; i < temp_idx; i++) {
		line[i] = temp_line[i];
	}

	if (temp_idx < line_idx) {
		for (int i = temp_idx; i < line_idx; i++) {
			line[i] = 0;
		}
	}

	line_idx = temp_idx;

	return;
}

void convert_to_board() {
	int tornado_dy[] = { 0,1,0,-1 };
	int tornado_dx[] = { -1,0,1,0 };

	int cy = n / 2;
	int cx = n / 2;
	int d = 0; //왼쪽 방향부터 토네이도 시작
	int loop_cnt = 2; //방향이 2번 변할 때마다 방향의 길이 증가

	int cur = 0;

	for (int dist = 1; dist < n; dist++) {
		if (dist == n - 1) loop_cnt = 3; //마지막은 3번으로 바꿔 배열 완성하기

		for (int i = 0; i < loop_cnt; i++) {
			for (int j = 0; j < dist; j++) {
				cy += tornado_dy[d];
				cx += tornado_dx[d];

				if (cur < line_idx) {
					board[cy][cx] = line[cur++];
				}
				else board[cy][cx] = 0;
			}

			d = (d + 1) % 4;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> d >> s;
		d--;

		blizzard(d, s);

		push_blank_and_convert_to_line();

		while (explode_and_get_point() != 0) {
			push_blank();
		}

		change();
		convert_to_board();
	}

	cout << ret;

	return 0;
}
