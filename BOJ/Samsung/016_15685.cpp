#include<iostream>
#include<climits> //INT_MAX
using namespace std;

const int dy[] = { 0,-1,0,1 };
const int dx[] = { 1,0,-1,0 };
int n, x, y, d, g, ret, gen, curve[1025];
bool a[101][101];

void makeDragon(int x, int y, int d, int g) {
	fill(curve, curve + 1024, 0);

	a[y][x] = true;
	gen = 0;

	curve[gen] = d; //입력된 d를 0세대 커브의 방향으로 저장
	gen++;

	//현재 드래곤 커브는 지금까지의 방향 집합을 역순, 반시계로 회전한 방향의 집합을 기존 방향에 추가한다
	for (int i = 0; i < g; i++) {
		for (int j = gen - 1; j >= 0; j--) {
			curve[gen] = (curve[j] + 1) % 4;
			gen++;
		}
	}

	for (int i = 0; i < gen; i++) {
		y += dy[curve[i]];
		x += dx[curve[i]];

		if (y < 0 || y >= 101 || x < 0 || x >= 101) continue;

		a[y][x] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		makeDragon(x, y, d, g);
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) {
				ret++;
			}
		}
	}

	cout << ret;

	return 0;
}
