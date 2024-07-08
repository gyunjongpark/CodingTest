#include<iostream>
#include<vector>
#define ALPHA 500000
#define MAX 1000004
using namespace std;

int n, xpos, ypos;
int cnt_x[MAX], cnt_y[MAX], s_x[MAX], s_y[MAX];
vector<pair<int,int>> pos;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for (int i = 0; i < n; i++) {
		cin >> xpos >> ypos;
		xpos += ALPHA;
		ypos += ALPHA;
		pos.push_back({ xpos,ypos });
	}

	for (int i = 0; i < n; i++) {
		int x = pos[i].first;
		int y = pos[i].second;
		int nx = pos[(i + 1) % n].first; //마지막 좌표는 첫 좌표로 돌아온다
		int ny = pos[(i + 1) % n].second;

		if (x == nx) {
			int max_y = max(y, ny);
			int min_y = min(y, ny);
			cnt_y[min_y]++;
			cnt_y[max_y]--;
		}
		else {
			int max_x = max(x, nx);
			int min_x = min(x, nx);
			cnt_x[min_x]++;
			cnt_x[max_x]--;
		}
	}

	for (int i = 1; i < 1000001; i++) {
		s_x[i] = s_x[i - 1] + cnt_x[i - 1];
		s_y[i] = s_y[i - 1] + cnt_y[i - 1];
	}

	int ret = 0;
	for (int i = 1; i < 1000001; i++) {
		ret = max(ret, max(s_x[i], s_y[i]));
	}
	cout << ret;

	return 0;
}
