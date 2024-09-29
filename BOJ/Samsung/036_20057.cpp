#include<iostream>
using namespace std;

const int dy[] = { 0,1,0,-1 };
const int dx[] = { -1,0,1,0 };
const int wind_dy[][9] = {
	{-1,1,-2,2,0,-1,1,-1,1}, //left
	{-1,-1,0,0,2,0,0,1,1}, //down
	{1,-1,2,-2,0,1,-1,1,-1}, //right
	{1,1,0,0,-2,0,0,-1,-1} //up
};
const int wind_dx[][9] = {
	{1,1,0,0,-2,0,0,-1,-1}, //left
	{-1,1,-2,2,0,-1,1,-1,1}, //down
	{-1,-1,0,0,2,0,0,1,1}, //right
	{1,-1,2,-2,0,1,-1,1,-1} //up
};
const int rate[] = { 1,1,2,2,5,7,7,10,10 };
int n, a[500][500], ret;
bool visited[500][500];

int wind(int y, int x, int dir) {
	int sand = a[y][x]; //초기 전체 모래
	int sum = 0; //생성된 모래의 합
	int ret = 0; //생성된 모래 중 범위를 벗어난 모래의 합
	

	//비율 자리의 모래 계산
	for (int i = 0; i < 9; i++) {
		int ny = y + wind_dy[dir][i];
		int nx = x + wind_dx[dir][i];

		int sand_by_wind = (sand * rate[i]) / 100;

		sum += sand_by_wind;

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
			ret += sand_by_wind;
		}
		else a[ny][nx] += sand_by_wind;
	}

	//alpha 자리의 모래 계산
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	//alpha로 이동하는 모래의 양은 비율이 적혀있는 칸으로 이동하지 않은 남은 모래의 양과 같다
	//(y, x) 기준: 초기 모래(a[y][x]) - 생성된 모래(sum) = alpha 좌표의 모래(alpha)
	int alpha = sand - sum;

	if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
		ret += alpha;
	}
	else a[ny][nx] += alpha;

	a[y][x] = 0; //a[y][x] - sum - alpha = 0

	return ret;
}

void go(int y, int x) {
	int dir = -1;

	//토네이도
	while (y != 0 || x != 0) {
		visited[y][x] = 1;

		int nd = (dir + 1) % 4; //다음 좌표는 왼쪽으로 꺾어서 한 칸 이동
		int ny = y + dy[nd];
		int nx = x + dx[nd];

		if (visited[ny][nx]) { //이미 방문되어 있다면 기존 방향으로 한 칸 더 전진
			nd = dir % 4;
			ny = y + dy[nd];
			nx = x + dx[nd];
		}

		ret += wind(ny, nx, nd);

		dir = nd;
		y = ny;
		x = nx;
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

	go(cy, cx);

	cout << ret;

	return 0;
}
