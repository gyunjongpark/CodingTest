#include<iostream>
#include<vector>
using namespace std;

struct Fireball {
	int y, x, m, s, d;
};
vector<Fireball> ball;

const int dy[] = { -1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int n, m, k, ret;
vector<int> pos[51][51];

void move() {
	vector<int> temp[51][51];

	for (int i = 0; i < ball.size(); i++) {
		int dir = ball[i].d;
		int speed = ball[i].s % n;

		int ny = (ball[i].y + (dy[dir] * speed) + n) % n;
		int nx = (ball[i].x + (dx[dir] * speed) + n) % n;

		temp[ny][nx].push_back(i);

		ball[i].y = ny;
		ball[i].x = nx;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pos[i][j] = temp[i][j];
		}
	}

	return;
}

void combine() {
	vector<Fireball> new_ball;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (pos[i][j].size() == 0) continue; //좌표에 파이어볼이 없을 경우
			if (pos[i][j].size() == 1) { //좌표에 파이어볼이 1개 있을 경우
				int idx = pos[i][j][0];

				new_ball.push_back(ball[idx]);
				continue;
			}

			//좌표에 파이어볼이 2개 이상인 경우
			int sum_m = 0, sum_s = 0;
			bool odd = true, even = true;

			for (int cnt = 0; cnt < pos[i][j].size(); cnt++) {
				int idx = pos[i][j][cnt];

				sum_m += ball[idx].m;
				sum_s += ball[idx].s;

				if (ball[idx].d % 2 == 0) { //방향이 짝수라면
					odd = false;
				}
				else even = false; //홀수라면
			}

			if (sum_m / 5 == 0) continue; //나누어진 파이어볼의 질량이 0이라면 소멸된다

			int cur_m = sum_m / 5;
			int cur_s = sum_s / pos[i][j].size();

			for (int dir = 0; dir < 4; dir++) {
				if (odd || even) { //모두 짝수이거나 모두 홀수라면
					new_ball.push_back({ i,j,cur_m,cur_s,dir * 2 });
				}
				else {
					new_ball.push_back({ i,j,cur_m,cur_s,dir * 2 + 1 });
				}
			}
		}
	}

	ball = new_ball; //ball 갱신

	return;
}

void go() {
	while (k--) {
		move();
		combine();
	}

	for (int i = 0; i < ball.size(); i++) {
		ret += ball[i].m;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int y, x, m, s, d;
		cin >> y >> x >> m >> s >> d;
		y--, x--;

		ball.push_back({ y,x,m,s,d });
		pos[y][x].push_back(i); //좌표에 해당 파이어볼의 인덱스 저장
	}

	go();

	cout << ret;

	return 0;
}
