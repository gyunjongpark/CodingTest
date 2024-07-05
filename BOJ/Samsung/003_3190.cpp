#include<iostream>
#include<vector>
#include<deque>
#define MAX 104
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

deque<pair<int, int>> v, dq;

int _time, n, k, l, y, x, _y, _x, t, dir;
bool visited[MAX][MAX], a[MAX][MAX];
char c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < k; i++) { //apple
		cin >> y >> x;
		a[y - 1][x - 1] = 1;
	}

	cin >> l;

	for (int i = 0; i < l; i++) {
		cin >> t >> c;
		if (c == 'D') v.push_back({ t,1 }); //right
		else v.push_back({ t,3 }); //left
	}

	dq.push_back({ 0,0 }); //init
	dir = 1; //init

	while (dq.size()) {
		_time++;

		_y = dq.front().first;
		_x = dq.front().second;
    
		int ny = _y + dy[dir];
		int nx = _x + dx[dir];

		if (ny >= n || ny < 0 || nx >= n || nx < 0 || visited[ny][nx]) break;
		

		visited[ny][nx] = 1;
		dq.push_front({ ny,nx });

		if (a[ny][nx]) {
			a[ny][nx] = 0;
		}
		else {
			visited[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}

		if (_time == v.front().first) {
			dir = (dir + v.front().second) % 4;
			v.pop_front();
		}
	}
	cout << _time;

	return 0;
}
