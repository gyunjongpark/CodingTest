#include<iostream>
#include<vector>
#include<queue>
#include<tuple> //tie
using namespace std;

int dy1[] = { 0,-1,0,1 };
int dx1[] = { 1,0,-1,0 };
int dy2[] = { 0,1,0,-1 };
int dx2[] = { 1,0,-1,0 };
int r, c, t, temp[54][54], a[54][54], ret;
vector<pair<int, int>> v1, v2;


void spread() {
	fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);

	queue<pair<int, int>> q;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] != -1 && a[i][j]) {
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front(); q.pop();

		int dust = a[y][x] / 5;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy1[i];
			int nx = x + dx1[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == -1) continue;

			temp[ny][nx] += dust; //더하는 것은 다른 칸에 영향을 끼치는 것이므로 temp를 따로 만든 후 연산
			a[y][x] -= dust; //빼는 것은 영향을 끼치지 않으므로 a 배열에서 직접 연산
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] += temp[i][j];
		}
	}

	return;
}

vector<pair<int, int>> cleanList(int sy, int sx, int dy[], int dx[]) {
	vector<pair<int, int>> v;
	int y, x;
	tie(y, x) = { sy,sx };

	int dir = 0;

	while (true) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
			dir++;

			ny = y + dy[dir];
			nx = x + dx[dir];
		}

		if (ny == sy && nx == sx) break;

		v.push_back({ ny,nx });
		tie(y, x) = { ny,nx };
	}

	return v;
}

void clean(vector<pair<int, int>>& v) {
	for (int i = v.size() - 1; i > 0; i--) {
		a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
	}

	a[v[0].first][v[0].second] = 0;

	return;
}

int main() {
	cin >> r >> c >> t;

	bool flag = true;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];

			if (a[i][j] == -1) {
				if (flag) {
					v1 = cleanList(i, j, dy1, dx1);
					flag = false;
				}
				else v2 = cleanList(i, j, dy2, dx2);
			}
		}
	}

	while (t--) {
		spread();
		clean(v1);
		clean(v2);
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] != -1 && a[i][j]) {
				ret += a[i][j];
			}
		}
	}

	cout << ret;

	return 0;
}
