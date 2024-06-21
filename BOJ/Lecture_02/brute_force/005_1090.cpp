#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v;
vector<int> xpos, ypos;
int n, x, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x,y }); //움직일 좌표 입력
		xpos.push_back(x); //최소 거리가 될 수 있는 x 좌표 입력
		ypos.push_back(y); //최소 거리가 될 수 있는 y 좌표 입력
	}

	vector<int> answer(n, -1); //init
	for (int y : ypos) {
		for (int x : xpos) {
			vector<int> dist; //거리 차이 담기

			for (pair<int, int> pi : v) { //움직일 좌표 전체 조사
				int d = abs(pi.first - x) + abs(pi.second - y);
				dist.push_back(d);
			}

			sort(dist.begin(), dist.end());

			int tmp = 0;
			for (int i = 0; i < n; i++) {
				tmp += dist[i]; //tmp는 i개의 체커가 모이는 횟수가 된다
				if (answer[i] == -1) {
					answer[i] = tmp; //배열에 값이 처음 들어왔다면 tmp로 일단 배정
				}
				else {
					//answer[i]는 i개의 체커가 모이는 최소 횟수가 된다
					answer[i] = min(tmp, answer[i]);
				}
			}
		}
	}
	for (int ret : answer) cout << ret << ' '; //i에 따라 체커가 모이는 최소 횟수 출력

	return 0;
}
