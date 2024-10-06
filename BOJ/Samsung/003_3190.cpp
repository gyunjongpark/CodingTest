#include<iostream>
#include<vector>
#include<deque>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, k, y, x, l, t, dir, ret;
bool a[101][101], visited[101][101];
char c;
deque<pair<int, int>> dq, v;

void go() {
	dq.push_back({ 0,0 });
	visited[0][0] = 1;
	dir = 1;

	while (!dq.empty()) {
		ret++;

		int ny = dq.front().first + dy[dir];
		int nx = dq.front().second + dx[dir];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) break; //벽에 부딪히는 경우
		if (visited[ny][nx]) break; // 자기자신의 몸과 부딪히는 경우

		dq.push_front({ ny,nx });
		visited[ny][nx] = 1;

		if (a[ny][nx] == 1) {
			a[ny][nx] = 0;
		}
		else {
			//몸길이를 줄인다
			visited[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}

		if (ret == v.front().first) { //입력된 시간이 되면 방향을 바꾼다
			dir = (dir + v.front().second) % 4;
			v.pop_front();
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		a[y - 1][x - 1] = 1;
	}

	cin >> l;

	for (int i = 0; i < l; i++) {
		cin >> t >> c;

		if (c == 'D') v.push_back({ t,1 });
		else v.push_back({ t,3 });
	}

	go();

	cout << ret;

	return 0;
}
