#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, x, y;
vector<pair<int, int>> v;
vector<int> xpos, ypos;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
		xpos.push_back(x);
		ypos.push_back(y);
	}

	vector<int> answer(n,-1);
	for (int y : ypos) { //모든 좌표에 대해서
		for (int x : xpos) { //모든 좌표에 대해서
			vector<int> dist;

			for (pair<int, int> pi : v) { //{x,y} 해당 좌표와의 거리 계산
				int d = abs(pi.first - x) + abs(pi.second - y);
				dist.push_back(d);
			}
			sort(dist.begin(), dist.end());

			int tmp = 0;
			for (int i = 0; i < n; i++) { //체커의 개수에 따른 최소거리 계산
				tmp += dist[i];
				if (answer[i] == -1) {
					answer[i] = tmp;
				}
				else {
					answer[i] = min(tmp, answer[i]);
				}
			}
		}
	}
	for (int ret : answer) cout << ret << ' ';

	return 0;
}
