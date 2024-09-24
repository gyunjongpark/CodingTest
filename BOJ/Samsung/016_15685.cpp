#include<iostream>
#include<climits> //INT_MAX
using namespace std;

const int dy[] = { 0,-1,0,1 };
const int dx[] = { 1,0,-1,0 };
int n, x, y, d, g, ret, gen, curve[1024];
bool a[101][101];

void makeDragon(int x, int y, int d, int g) {
	a[y][x] = 1; //시작 좌표는 무조건 true

	//init
	gen = 0;
	fill(curve, curve + 1024, 0);

	curve[gen++] = d; //0세대 방향을 curve[0]에 저장 후 세대 증가

	for (int i = 0; i < g; i++) {
		for (int j = gen - 1; j >= 0; j--) { //현재 세대부터 역순으로 저장
			curve[gen++] = (curve[j] + 1) % 4;
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

//방향을 따져보고 규칙성 찾기
//논리를 따져보고 규칙성 찾기. 14890(경사로)문제와 접근 방식이 유사하다
