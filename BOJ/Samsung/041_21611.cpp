#include<iostream>
using namespace std;

//블리자드를 시전할 방향 설정
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
int n, m, line_idx, line[2500], board[49][49], ret;

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

void convert_to_line() {
	//좌,하,우,상
	int ddy[] = { 0,1,0,-1 };
	int ddx[] = { -1,0,1,0 };

	line_idx = 0;

	int cy = n / 2;
	int cx = n / 2;
	int d = 0; //왼쪽 방향부터 시작
	int loop_cnt = 2; //같은 길이의 진행을 몇번 반복하는가?

	for (int dist = 1; dist < n; dist++) { //길이는 1부터 시작
		if (dist == n - 1) {
			loop_cnt = 3; //길이가 n - 1이 되면 3번 반복하면서 2차원 배열을 완성시킨다
		}

		for (int i = 0; i < loop_cnt; i++) {
			for (int j = 0; j < dist; j++) { //dist의 길이만큼 해당 방향으로 진행
				cy += ddy[d];
				cx += ddx[d];

				if (board[cy][cx] != 0) {
					line[line_idx] = board[cy][cx];
					line_idx++;
				}
			}

			d = (d + 1) % 4;
		}
	}

	return;
}

int get_point() {
	int point = 0;
	int same_cnt = 1; //현재 구슬의 값 기준

	for (int i = 1; i < line_idx; i++) {
		if (line[i - 1] == line[i]) {
			same_cnt++;
		}
		else {
			if (same_cnt >= 4) {
				for (int j = 1; j <= same_cnt; j++) {
					point += line[i - j];
					line[i - j] = 0;
				}
			}

			same_cnt = 1;
		}
	}

	if (same_cnt >= 4) {
		for (int j = 1; j <= same_cnt; j++) {
			point += line[line_idx - j];
			line[line_idx - j] = 0;
		}
	}

	ret += point;

	return point;
}

void remove_blank() {
	int temp_size = 0;
	int temp_line[2500] = { 0, };

	for (int i = 0; i < line_idx; i++) {
		if (line[i] != 0) {
			temp_line[temp_size] = line[i];
			temp_size++;
		}
	}

	for (int i = 0; i < temp_size; i++) {
		line[i] = temp_line[i];
	}

	for (int i = temp_size; i < line_idx; i++) {
		line[i] = 0;
	}

	line_idx = temp_size;

	return;
}

void expand() {
	int temp_size = 0;
	int temp_board[2500] = { 0, };

	int cnt = 1;

	for (int i = 1; i < line_idx; i++) {
		if (line[i - 1] == line[i]) {
			cnt++;
		}
		else {
			if (temp_size < n * n - 2) { //한번 확장 시 2칸씩 소모한다
				temp_board[temp_size++] = cnt;
				temp_board[temp_size++] = line[i - 1];
			}

			cnt = 1;
		}
	}

	if (line_idx > 0 && temp_size < n * n - 2) {
		temp_board[temp_size++] = cnt;
		temp_board[temp_size++] = line[line_idx - 1];
	}

	for (int i = 0; i < temp_size; i++) {
		line[i] = temp_board[i];
	}

	line_idx = temp_size;

	return;
}

void convert_to_board() {
	int ddy[] = { 0,1,0,-1 };
	int ddx[] = { -1,0,1,0 };

	int cy = n / 2;
	int cx = n / 2;
	int d = 0; //왼쪽부터 시작
	int loop_cnt = 2; //방향을 바꾸는 주기. 마지막은 3으로 수정 후 board를 완성한다
	int cur = 0;

	for (int dist = 1; dist < n; dist++) { //방향이 중복된 횟수 dist
		if (dist == n - 1) {
			loop_cnt = 3;
		}

		for (int i = 0; i < loop_cnt; i++) {
			for (int j = 0; j < dist; j++) {
				cy += ddy[d];
				cx += ddx[d];

				if (cur < line_idx) {
					board[cy][cx] = line[cur];
					cur++;
				}
				else {
					board[cy][cx] = 0;
				}
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

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> board[y][x];
		}
	}

	for (int i = 0; i < m; i++) { //상어가 구슬을 파괴하는 횟수(블리자드)
		int d, s; //dir, size

		cin >> d >> s;
		d--; //인덱싱

		blizzard(d, s); //구슬 파괴
		convert_to_line(); //공백을 제외한 구슬의 번호를 1차원 배열로 저장

		while (get_point() != 0) { //파괴로 인한 점수를 얻을 때까지 진행
			remove_blank(); //파괴되어 점수를 얻었다면 공백 지우기
		}

		expand(); //구슬 확장
		convert_to_board(); //2차원으로 변환
	}

	cout << ret;

	return 0;
}
