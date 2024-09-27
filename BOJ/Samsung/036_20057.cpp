#include<iostream>
using namespace std;

const int wind_y[4][9] = {
	{-1,1,-2,2,0,-1,1,-1,1}, //left
	{-1,-1,0,0,2,0,0,1,1}, //down
	{1,-1,2,-2,0,1,-1,1,-1}, //right
	{1,1,0,0,-2,0,0,-1,-1} //up
};
const int wind_x[][9] = {
	{1,1,0,0,-2,0,0,-1,-1}, //left
	{-1,1,-2,2,0,-1,1,-1,1}, //down
	{-1,-1,0,0,2,0,0,1,1}, //right
	{1,-1,2,-2,0,1,-1,1,-1} //up
};
const int rate[] = { 1,1,2,2,5,7,7,10,10 };
const int dy[] = { 0,1,0,-1 };
const int dx[] = { -1,0,1,0 };
int n, a[500][500], ret;

int wind(int cur_y, int cur_x, int cur_dir) {
	int sand = a[cur_y][cur_x];
	int ret = 0; //범위를 벗어난 모래의 양 저장
	int sum = 0; //생성된 모래의 양 저장(전체 - sum = alpha를 위해)

	for (int i = 0; i < 9; i++) {
		int ny = cur_y + wind_y[cur_dir][i];
		int nx = cur_x + wind_x[cur_dir][i];

		//좌표에 이동할 모래의 양
		int wind_sand = (sand * rate[i]) / 100;

		//alpha 모래를 계산하기 위해 sum으로 모래 합하기
		sum += wind_sand;		

		//그 중 격자 범위를 벗어났다면 ret에 모래의 양 추가로 저장
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
			ret += wind_sand;
			continue; //범위를 벗어나므로 이후 계산은 무의미하다
		}

		//기존값에 모래의 양 더하기
		a[ny][nx] += wind_sand;
	}

	//alpha 칸의 모래 계산하기
	int ny = cur_y + dy[cur_dir];
	int nx = cur_x + dx[cur_dir];

	//alpha 모래의 양은 비율이 적혀있는 칸으로 이동하지 않은 남은 모래의 양과 같다
	int alpha = (sand - sum);

	if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
		ret += alpha;
	}
	else a[ny][nx] += alpha;

	//y의 모든 모래가 비율과 alpha가 적혀있는 칸으로 이동한다
	a[cur_y][cur_x] = 0;

	return ret;
}

void go(int y, int x) {
	bool visited[500][500];
	fill(&visited[0][0], &visited[0][0] + 500 * 500, 0);

	int dir = -1; //방향 init

	//토네이도 테크닉! 암기 필수
	while (y != 0 || x != 0) {
		visited[y][x] = 1;

		int nd = (dir + 1) % 4; //dir 기준 왼쪽으로 계속 꺾는다

		int ny = y + dy[nd];
		int nx = x + dx[nd];

		if (visited[ny][nx]) {
			nd = dir % 4; //꺾지 않고 기존 방향을 유지한 채 한번 더 진행

			ny = y + dy[nd];
			nx = x + dx[nd];
		}

		//모래가 이동된 곳(목적지, y) 기준으로 wind 함수 진행
		ret += wind(ny, nx, nd);

		//좌표와 방향 갱신
		y = ny;
		x = nx;
		dir = nd;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int cy = n / 2;
	int cx = n / 2;

	go(cy, cx); //격자의 중앙에서 시작

	cout << ret;

	return 0;
}
