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
		v.push_back({ x,y }); //비교 좌표 입력
		xpos.push_back(x); //기준 좌표 입력
		ypos.push_back(y); //기준 좌표 입력
	}

	vector<int> answer(n, -1);
	for (int y : ypos) {
		for (int x : xpos) {
			vector<int> dist; //기준 좌표와 비교 좌표의 차이를 담는 vector

			for (pair<int, int> pi : v) { //{x,y}
				int d = abs(pi.first - x) + abs(pi.second - y);
				dist.push_back(d);
			}
			sort(dist.begin(), dist.end());

			int tmp = 0;
			for (int i = 0; i < n; i++) {
				tmp += dist[i]; //tmp는 i개의 체커가 모이는 횟수가 된다
				if (answer[i] == -1) {
					answer[i] = tmp;
				}
				else {
					answer[i] = min(tmp, answer[i]); //answer[i]는 i개의 체커가 모이는 최소 횟수가 된다
				}
			}
		}
	}
	for (int ret : answer) cout << ret << ' '; i에 따라서 체커가 모이는 최소 횟수 출력(오름차순)

	return 0;
}
