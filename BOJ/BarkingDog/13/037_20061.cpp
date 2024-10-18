#include<iostream>
using namespace std;

const int BLUE = 0;
const int GREEN = 1;
int t, x, y, n, score, ret, board[2][10][4]; //blue, green

void move_point(int y, int x, int color) {
	int label = board[color][y][x];

	board[color][y][x] = 0;

	while (y < 10) {
		//내려가는 도중에 다른 블록을 발견한다면
		if (board[color][y][x] != 0) {
			break;
		}

		y++;
	}

	y--;

	board[color][y][x] = label;

	return;
}

void limited_move_point(int y, int x, int color) {
	int label = board[color][y][x];

	board[color][y][x] = 0;

	if (board[color][y + 1][x] == 0) {
		y++;
		board[color][y][x] = label;
	}

	return;
}

void move_h_block(int y, int x, int color) {
	int label = board[color][y][x];

	board[color][y][x] = 0;
	board[color][y - 1][x] = 0;

	while (y < 10) {
		//내려가는 도중에 다른 블록을 발견한다면
		if (board[color][y][x] != 0) {
			break;
		}

		y++;
	}

	y--;

	board[color][y][x] = label;
	board[color][y - 1][x] = label;

	return;
}

void limited_h_block(int y, int x, int color) {
	int label = board[color][y][x];

	board[color][y][x] = 0;
	board[color][y - 1][x] = 0;

	if (board[color][y + 1][x] == 0) {
		y++;
		board[color][y][x] = label;
		board[color][y - 1][x] = label;
	}

	return;
}

void move_w_block(int y, int x, int color) {
	int label = board[color][y][x];

	board[color][y][x] = 0;
	board[color][y][x + 1] = 0;

	while (y < 10) {
		//내려가는 도중에 다른 블록을 발견한다면
		if (board[color][y][x] != 0 || board[color][y][x + 1] != 0) {
			break;
		}

		y++;
	}

	y--;

	board[color][y][x] = label;
	board[color][y][x + 1] = label;

	return;
}

void limited_w_block(int y, int x, int color) {
	int label = board[color][y][x];

	board[color][y][x] = 0;
	board[color][y][x + 1] = 0;

	if (board[color][y + 1][x] == 0) {
		y++;
		board[color][y][x] = label;
		board[color][y][x + 1] = label;
	}

	return;
}

void remove(int y, int color) {
	for (int x = 0; x < 4; x++) {
		board[color][y][x] = 0;
	}

	return;
}

void move(int start_y, int color) {
	const int dy[] = { -1,0 };
	const int dx[] = { 0,1 };

	for (int y = start_y; y >= 4; y--) {
		for (int x = 0; x < 4; x++) {
			if (board[color][y][x] == 0) continue;

			int type = 1;

			for (int d = 0; d < 2; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];

				if (ny < 4 || nx >= 4) continue;

				if (board[color][y][x] == board[color][ny][nx]) {
					if (d == 0) type = 2;
					else type = 3;
				}
			}
			if (type == 1) {
				limited_move_point(y, x, color);
			}
			else if (type == 2) {
				limited_h_block(y, x, color);
			}
			else if (type == 3) {
				limited_w_block(y, x, color);
			}
		}
	}

	return;
}

void delete_filled_block(int color) {
	bool is_remove = false;

	for (int y = 6; y < 10; y++) {
		int count = 0;

		for (int x = 0; x < 4; x++) {
			if (board[color][y][x] != 0) count++;
		}

		if (count == 4) {
			is_remove = true;
			score++;
			remove(y,color);
			move(y - 1, color);
		}
	}

	if (is_remove) {
		delete_filled_block(color);
	}

	return;
}

void delete_overflow_block(int color) {
	int remove_count = 0;

	for (int y = 4; y <= 5; y++) {
		bool has_block = false;
		
		for (int x = 0; x < 4; x++) {
			if (board[color][y][x] != 0) {
				has_block = true;
				break;
			}
		}

		if (has_block) {
			remove_count++;
		}
	}

	if (remove_count > 0) {
		for (int y = 9; y >= 6; y--) {
			for (int x = 0; x < 4; x++) {
				board[color][y][x] = board[color][y - remove_count][x];
			}
		}

		for (int y = 4; y <= 5; y++) {
			for (int x = 0; x < 4; x++) {
				board[color][y][x] = 0;
			}
		}
	}

	return;
}

void put(int type, int target, int color, int label) {
	if (type == 1) {
		board[color][0][target] = label;
		move_point(0, target, color);
	}
	else if ((type == 2 && color == BLUE) || (type == 3 && color == GREEN)) { //세로 블록
		board[color][0][target] = label;
		board[color][1][target] = label;
		move_h_block(1, target, color);
	}
	else if ((type == 3 && color == BLUE) || (type == 2 && color == GREEN)) { //가로 블록
		board[color][0][target] = label;
		board[color][0][target + 1] = label;
		move_w_block(0, target, color);
	}

	delete_filled_block(color);
	delete_overflow_block(color);

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t >> y >> x;

		put(t, y, BLUE, i + 1);
		put(t, x, GREEN, i + 1);
	}

	for (int color = 0; color < 2; color++) {
		for (int y = 4; y < 10; y++) {
			for (int x = 0; x < 4; x++) {
				if (board[color][y][x] != 0) ret++;
			}
		}
	}

	cout << score << '\n' << ret;

	return 0;
}
