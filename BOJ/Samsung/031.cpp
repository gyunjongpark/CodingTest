#include<iostream>
#include<vector>
using namespace std;

struct Fish {
	int y, x, dir;
	bool isDead;
};
Fish fish[16];

const int dy[] = { -1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int a, b, board[4][4], ret;

void dfs(int board[4][4], Fish fish[16], int shark_y, int shark_x, int sum) {
	int temp_board[4][4];
	Fish temp_fish[16];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp_board[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 16; i++) {
		temp_fish[i] = fish[i];
	}

	//eat
	int fish_number = temp_board[shark_y][shark_x];
	int shark_dir = temp_fish[fish_number].dir;

	temp_fish[fish_number].isDead = true;
	temp_board[shark_y][shark_x] = -1;

	sum += (fish_number + 1); //먹은 물고기 sum에 추가

	if (ret < sum) ret = sum;

	//fish move
	for (int f = 0; f < 16; f++) {
		if (temp_fish[f].isDead) continue;

		int cy = temp_fish[f].y;
		int cx = temp_fish[f].x;
		int cd = temp_fish[f].dir;

		int ny = cy + dy[cd];
		int nx = cx + dx[cd];
		int nd = cd; //다음 방향 또한 기존의 방향과 같다

		while (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || (ny == shark_y && nx == shark_x)) {
			nd = (nd + 1) % 8; //방향 전환

			//전환된 방향으로 다시 계산
			ny = cy + dy[nd]; 
			nx = cx + dx[nd];
		}

		if (temp_board[ny][nx] != -1) { //물고기가 있다면
			int target = temp_board[ny][nx];

			//기존의 물고기 좌표를 바꿀 물고기 좌표로 변경
			temp_fish[target].y = cy;
			temp_fish[target].x = cx;

			//계산된 ny, nx, nd를 현재 인덱스의 물고기의 정보로 갱신
			temp_fish[f].y = ny;
			temp_fish[f].x = nx;
			temp_fish[f].dir = nd;

			//board의 정보 변경
			temp_board[ny][nx] = f;
			temp_board[cy][cx] = target;
		}
		else {
			//물고기가 없다면 바로 갱신
			temp_fish[f].y = ny;
			temp_fish[f].x = nx;
			temp_fish[f].dir = nd;

			temp_board[ny][nx] = f;
			temp_board[cy][cx] = -1; //없는 물고기는 -1
		}
	}

	//shark move
	for (int step = 1; step < 4; step++) {
		int ny = shark_y + dy[shark_dir] * step;
		int nx = shark_x + dx[shark_dir] * step;

		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) break;

		if (temp_board[ny][nx] != -1) {
			dfs(temp_board, temp_fish, ny, nx, sum);
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b; //물고기의 번호와 방향
			a--, b--; //인덱스 연산을 위한 -1

			fish[a] = { i,j,b,0 }; //y, x, dir, isDead

			board[i][j] = a; //0 ~ 15
		}
	}

	dfs(board, fish, 0, 0, 0);

	cout << ret;

	return 0;
}
