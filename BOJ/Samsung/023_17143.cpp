#include<iostream>
#include<cstring> //memset,memcpy
using namespace std;

struct shark {
	int r, c, s, d, z;
	bool isDead;
};
shark a[10001]; //상어 목록 저장

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,1,-1 };
int r, c, m, pos[101][101], temp[101][101], ret;

void go() {
	for (int xpos = 0; xpos < c; xpos++) { //1. 낚시왕이 오른쪽으로 한 칸 이동한다
		for (int ypos = 0; ypos < r; ypos++) {
			if (pos[ypos][xpos]) { //2. 제일 가까운 상어를 잡는다
				a[pos[ypos][xpos]].isDead = true;
				ret += a[pos[ypos][xpos]].z; //낚시왕이 잡은 상어 크기의 합
				pos[ypos][xpos] = 0; //격자판에서 잡은 상어가 사라진다

				break; //해당 열에서는 더이상 작업을 하지 않는다
			}
		}

		//3. 상어가 이동한다
		fill(&temp[0][0], &temp[0][0] + 101 * 101, 0);

		for (int i = 1; i <= m; i++) {
			if (a[i].isDead) continue;

			int y = a[i].r;
			int x = a[i].c;
			int s = a[i].s;
			int d = a[i].d;
			int z = a[i].z;

			int ny, nx;

			while (true) { //최종적인 ny, nx 정하기
				ny = y + s * dy[d];
				nx = x + s * dx[d];

				if (ny >= 0 && ny < r && nx >= 0 && nx < c) break;

				if (d <= 1) {
					if (ny < 0) {
						s -= y;
						y = 0;
					}
					else {
						s -= (r - 1) - y;
						y = r - 1;
					}
				}
				else {
					if (nx < 0) {
						s -= x;
						x = 0;
					}
					else {
						s -= (c - 1) - x;
						x = c - 1;
					}
				}

				d ^= 1;
			}

			if (temp[ny][nx]) { //좌표에 이미 상어가 있다면 크기 비교 후 갱신
				if (a[temp[ny][nx]].z < a[i].z) {
					a[temp[ny][nx]].isDead = true;
					temp[ny][nx] = i;
				}
				else a[i].isDead = true;
			}
			else temp[ny][nx] = i;

			//i번째 상어의 정보 갱신
			a[i].r = ny;
			a[i].c = nx;
			a[i].d = d;
			//a[i].s = s; 움직인 후에도 같은 속도 성분을 유지한다
			a[i].z = z;
		}

		memcpy(pos, temp, sizeof(temp));
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> m;

	for (int i = 1; i <= m; i++) {
		cin >> a[i].r >> a[i].c >> a[i].s >> a[i].d >> a[i].z;
		a[i].r--, a[i].c--, a[i].d--;

		//모듈러 연산으로 격자 범위 내 속도로 맞추기
		if (a[i].d <= 1) a[i].s %= (2 * (r - 1));
		else a[i].s %= (2 * (c - 1));

		pos[a[i].r][a[i].c] = i; //좌표에 해당 상어의 인덱스 저장
	}

	go();

	cout << ret;

	return 0;
}
