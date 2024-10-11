#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, board[20][20], ret;

int cal_point() {
	int point = 0;
	vector<int> max_area;
	int max_rainbow = 0;

	for (int color = 1; color <= m; color++) {
		bool visited[21][21] = { false, }; //무지개 블록의 처리를 위해 색상마다 visited 갱신

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (visited[y][x] == false && board[y][x] == color) {
					queue<int> q; //블록을 순차적으로 검사하기 위한 queue
					vector<int> v; //조건에 만족하는 블록들을 저장하기 위한 vector
					int rainbow = 0;

					q.push(y * 100 + x);
					v.push_back(y * 100 + x);
					visited[y][x] = true;


					while (!q.empty()) {
						int cy = q.front() / 100;
						int cx = q.front() % 100;

						q.pop();

						for (int d = 0; d < 4; d++) {
							int ny = cy + dy[d];
							int nx = cx + dx[d];

							if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

							if (visited[ny][nx] == false && (board[ny][nx] == color || board[ny][nx] == 0)) {
								q.push(ny * 100 + nx);
								v.push_back(ny * 100 + nx);
								visited[ny][nx] = true;

								if (board[ny][nx] == 0) {
									rainbow++;
								}
							}
						}
					}

					//블록 그룹의 기준 블록은 무지개 블록이 아닌 블록 중에서 행의 번호가 가장 작은 블록, 그러한 블록이 여러개면 열의 번호가 가장 작은 블록이다
					if (max_area.size() < v.size() || (max_area.size() == v.size() && max_rainbow < rainbow)
						|| (max_area.size() == v.size() && max_rainbow == rainbow && max_area[0] < v[0])) {
						//안전한 복사법 1 : 정확한 범위를 알고 반복문으로 복사
						//안전한 복사법 2 : resize + copy(deep copy. = 연산과 같은 작용을 한다)
						max_area.resize(v.size());
						copy(v.begin(), v.end(), max_area.begin()); //copy(복사할 범위 처음, 끝, 목적지 처음)

						max_rainbow = rainbow;
					}
				}
			}
		}
	}

	if (max_area.size() >= 2) {
		point = max_area.size() * max_area.size();

		for (int i = 0; i < max_area.size(); i++) {
			int y = max_area[i] / 100;
			int x = max_area[i] % 100;

			board[y][x] = -2; //empty 처리
		}
	}

	return point;
}

void down() {
	for (int x = 0; x < n; x++) {
		int blank = 0;

		for (int y = n - 1; y >= 0; y--) {
			if (board[y][x] == -2) {
				blank++;
			}
			else if (board[y][x] == -1) {
				blank = 0;
			}
			else {
				if (blank != 0) {
					board[y + blank][x] = board[y][x];
					board[y][x] = -2;
				}
			}
		}
	}

	return;
}

void rotate() {
	int temp[21][21];

	for (int i = 0; i < n; i++) { //열
		for (int j = 0; j < n; j++) { //행
			temp[n - j - 1][i] = board[i][j]; //반시계 방향으로 90도 회전
			//temp[i][j] = board[n - j - 1][i]; //시계 방향으로 90도 회전

		}
	}

	for (int i = 0; i < n; i++) { //행
		for (int j = 0; j < n; j++) { //열
			board[i][j] = temp[i][j]; //복사
		}
	}

	return;
}

void solve() {
	int point = 0;
	int cur_point = 0;

	do {
		cur_point = cal_point();
		point += cur_point;

		down();
		rotate();
		down();
	} while (cur_point != 0);

	ret = point;

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

	solve();

	cout << ret;

	return 0;
}
