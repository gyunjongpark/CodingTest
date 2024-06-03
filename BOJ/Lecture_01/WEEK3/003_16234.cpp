#include<iostream>
#include<vector>
#define MAX 51
using namespace std;

bool visited[MAX][MAX];
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, l, r, cnt, sum, a[MAX][MAX];
vector<pair<int,int>> v;

void dfs(int y, int x) {
	sum += a[y][x];
	visited[y][x] = 1;
	v.push_back({ y,x }); //인구 이동이 발생한 좌표 저장

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

		int diff = abs(a[y][x] - a[ny][nx]);
		if (!visited[ny][nx] && l <= diff && diff <= r) {
			dfs(ny, nx);
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	while (true) {
		bool flag = 0;
		fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0);
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				v.clear();
				sum = 0;

				if (!visited[i][j]) {
					dfs(i, j);

					if (v.size() == 1) continue; //인구 이동 없으면 다음 좌표로
					else { //인구 이동 발생 시
						for (pair<int, int> b : v) {
							a[b.first][b.second] = sum / v.size();
						}
						flag = 1; //인구이동 발생 flag
					}
				}
			}
		}
		if (!flag) break; //모든 좌표에서 인구 이동이 발생하지 않으면 break
		cnt++;
	}
	cout << cnt;

	return 0;
}
