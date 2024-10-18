#include<iostream>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, q, board[64][64];

void rotate(int cy, int cx, int len, int unit) {
	if (len == unit) {
		int temp[64][64];

		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				temp[cy + j][cx + len - i - 1] = board[cy + i][cx + j];
			}
		}

		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				board[cy + i][cx + j] = temp[cy + i][cx + j];
			}
		}

		return;
	}

	len /= 2;

	rotate(cy, cx, len, unit);
	rotate(cy, cx + len, len, unit);
	rotate(cy + len, cx, len, unit);
	rotate(cy + len, cx + len, len, unit);

	return;
}

void melt() {
	int len = 1 << n;
	int temp[64][64];

	for (int y = 0; y < len; y++) {
		for (int x = 0; x < len; x++) {
			int cnt = 0;

			for (int d = 0; d < 4; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];

				if (ny < 0 || ny >= len || nx < 0 || nx >= len) continue;
				if (board[ny][nx] == 0) continue;

				cnt++;
			}

			if (cnt >= 3 || board[y][x] == 0) {
				temp[y][x] = board[y][x];
			}
			else temp[y][x] = board[y][x] - 1;
		}
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			board[i][j] = temp[i][j];
		}
	}

	return;
}

void dfs(int y, int x, bool visited[64][64], int& size) {
	size++;

	int len = 1 << n;

	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny < 0 || ny >= len || nx < 0 || nx >= len) continue;

		if (!visited[ny][nx] && board[ny][nx]) {
			visited[ny][nx] = true;
			dfs(ny, nx, visited, size);
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> q;

	int len = 1 << n; //2^n

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cin >> board[i][j];
		}
	}

	while (q--) {
		int l;

		cin >> l;

		if (l > 0) {
			rotate(0, 0, len, (1 << l));
		}

		melt();
	}

	int total = 0, max_size = 0;
	bool visited[64][64] = { false, };

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			total += board[i][j];

			if (!visited[i][j] && board[i][j] != 0) {
				visited[i][j] = true;

				int cur_size = 0;

				dfs(i, j, visited, cur_size);

				if (max_size < cur_size) {
					max_size = cur_size;
				}
			}
		}
	}

	cout << total << '\n' << max_size;

	return 0;
}
