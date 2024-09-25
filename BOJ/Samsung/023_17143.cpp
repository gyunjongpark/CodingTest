#include<iostream>
#include<cstring> //memset,memcpy
using namespace std;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,1,-1 };
struct shark {
	int r, c, s, d, z;
	bool isDead;
};
shark a[10001]; //상어 목록 저장
int r, c, m, shark_pos[101][101], temp[101][101], ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> m;

	for (int i = 1; i <= m; i++) {
		cin >> a[i].r >> a[i].c >> a[i].s >> a[i].d >> a[i].z;
		a[i].r--, a[i].c--, a[i].d--;

		if (a[i].d <= 1) a[i].s %= (2 * (r - 1));
		else a[i].s %= (2 * (c - 1));

		//i번째 상어의 y, x좌표를 shark_pos에 저장
		//상어목록 a를 통해 a[i](i번째 상어)의 모든 정보를 알 수 있다
		shark_pos[a[i].r][a[i].c] = i;
	}

	for (int xpos = 0; xpos < c; xpos++) { //1. 낚시왕이 오른쪽으로 한 칸 이동한다
		for (int ypos = 0; ypos < r; ypos++) {
			if (shark_pos[ypos][xpos]) { //2. 상어를 발견했다면
				a[shark_pos[ypos][xpos]].isDead = true;
				ret += a[shark_pos[ypos][xpos]].z;
				shark_pos[ypos][xpos] = 0; //더 이상 해당 좌표에 상어는 없다

				break; //같은 ypos에 대해 상어를 잡지 않고 break
			}
		}

		//3. 상어가 이동한다	
		fill(&temp[0][0], &temp[0][0]+101*101, 0); //m마리의 상어가 움직인 결과를 저장하는 배열 temp
		
		for (int i = 1; i <= m; i++) { //m마리의 상어에 대해서
			if (a[i].isDead) continue; //죽은 상어는 continue

			int y = a[i].r;
			int x = a[i].c;
			int s = a[i].s;
			int d = a[i].d;
			int z = a[i].z;

			int ny, nx; //next

			while (true) {
				ny = y + s * dy[d];
				nx = x + s * dx[d];

				if (ny >= 0 && ny < r && nx >= 0 && nx < c) break;

				if (d <= 1) {
					if (ny < 0) {
						s -= y;
						y = 0;
					}
					else { //ny >= r
						s -= (r - 1) - y;
						y = r - 1;
					}
				}
				else {
					if (nx < 0) {
						s -= x;
						x = 0;
					}
					else { //nx >= c
						s -= (c - 1) - x;
						x = c - 1;
					}
				}

				d ^= 1; //비트 연산으로 방향 전환
			}

			if (temp[ny][nx]) { //ny, nx에 이미 움직임을 마친 상어가 있다면
				if (a[temp[ny][nx]].z < a[i].z) { //그 상어가 현재 상어보다 작다면
					a[temp[ny][nx]].isDead = true;
					temp[ny][nx] = i; //현재 상어로 대체
				}
				else a[i].isDead = true; //기존의 상어가 크다면 현재 상어가 사라진다
			}
			else temp[ny][nx] = i; //현재 상어를 ny, nx 좌표에 저장한다

			a[i].r = ny;
			a[i].c = nx;
			a[i].d = d;
			//a[i].s = s; 움직인 후에도 맨 처음 입력된 속도 성분을 그대로 가지고 있다
			a[i].z = z;
		}

		memcpy(shark_pos, temp, sizeof(temp));
	}
	
	cout << ret;

	return 0;
}
