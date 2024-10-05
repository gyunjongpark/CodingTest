#include<iostream>
using namespace std;

struct Fish {
	int y, x, dir;
	bool isDead;
};
Fish fishes[16];

const int dy[] = { -1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int a, b, board[4][4], ret;

void dfs(int board[4][4], Fish fishes[16], int shark_y, int shark_x, int sum) {
	int temp_board[4][4];
	Fish temp_fishes[16];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp_board[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 16; i++) {
		temp_fishes[i] = fishes[i];
	}

	//eat
	int fish_num = temp_board[shark_y][shark_x]; //현재 상어가 잡은 물고기의 번호
	int shark_dir = temp_fishes[fish_num].dir; //잡은 물고기의 방향이 상어의 방향이 된다

	temp_fishes[fish_num].isDead = true;
	temp_board[shark_y][shark_x] = -1; //물고기의 번호가 0 ~ 15이므로 -1로 공백 표시

	sum += (fish_num + 1); //잡아먹은 실제 번호는 인덱스 + 1

	if (ret < sum) ret = sum; //누적 합이 ret보다 크다면 ret 갱신

	//fish move
	for (int f = 0; f < 16; f++) {
		if (temp_fishes[f].isDead) continue; //죽은 물고기는 continue

		int cy = temp_fishes[f].y;
		int cx = temp_fishes[f].x;
		int cd = temp_fishes[f].dir;

		int ny = cy + dy[cd];
		int nx = cx + dx[cd];
		int nd = cd; //연산 후 격자 범위 내에 있다면 방향은 바뀌지 않는다

		//격자의 특성 상 무한루프는 발생하지 않는다
		//범위 밖이거나 상어가 있다면
		while (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || (ny == shark_y && nx == shark_x)) {
			//nd를 기반한 ny,nx가 범위 안으로 들어올 때까지 변경
			nd = (nd + 1) % 8;

			//수정된 nd를 기반으로 cy,cx에서 다시 ny,nx를 도출
			ny = cy + dy[nd];
			nx = cx + dx[nd];
		}

		if (temp_board[ny][nx] != -1) { //ny,nx에 물고기가 이미 있다면
			int cur_fish = temp_board[ny][nx]; //현재 ny,nx에 저장된 물고기의 번호

			//해당 물고기의 좌표만 cy,cx로 변경
			temp_fishes[cur_fish].y = cy;
			temp_fishes[cur_fish].x = cx;
			//temp_fishes[cur_fish].dir = nd; //물고기의 방향은 유지

			temp_fishes[f].y = ny;
			temp_fishes[f].x = nx;
			temp_fishes[f].dir = nd;

			temp_board[ny][nx] = f;
			temp_board[cy][cx] = cur_fish;
		}
		else { //물고기가 없다면
			temp_fishes[f].y = ny;
			temp_fishes[f].x = nx;
			temp_fishes[f].dir = nd;

			temp_board[ny][nx] = f;
			temp_board[cy][cx] = -1; //물고기가 없다면
		}
	}

	//shark move
	for (int step = 1; step < 4; step++) {
		int ny = shark_y + dy[shark_dir] * step;
		int nx = shark_x + dx[shark_dir] * step;

		//현재 step에서 범위를 벗어났다면 다음 step은 당연히 범위를 벗어나므로 break
		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) break;

		if (temp_board[ny][nx] != -1) {
			dfs(temp_board, temp_fishes, ny, nx, sum);
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
			a--, b--; //인덱싱을 위한 후위 감소 연산

			board[i][j] = a; //0 ~ 15
			fishes[a] = { i,j,b,0 }; //0 ~ 15
		}
	}

	dfs(board, fishes, 0, 0, 0); //격자, 물고기 배열, 상어y, 상어x, 먹은 양

	cout << ret;

	return 0;
}
