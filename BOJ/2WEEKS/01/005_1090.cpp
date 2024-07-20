#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, x, y;
vector<int> xpos, ypos;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		
		xpos.push_back(x);
		ypos.push_back(y);
		v.push_back({ x,y });
	}

	vector<int> answer(n, -1); //init
	
	for (int x : xpos) {
		for (int y : ypos) {
			vector<int> dist;

			for (pair<int, int> pi : v) {
				int d = abs(x - pi.first) + abs(y - pi.second); //문제 내 정의된 최소 이동거리 공식
				dist.push_back(d);
			}
			
			//하나의 (x, y) 좌표에 대하여 각 체커별로 최소 이동거리를 구한 후 오름차순 정렬
			sort(dist.begin(), dist.end());

			int temp = 0;
			for (int i = 0; i < n; i++) {
				temp += dist[i]; //하나의 좌표에서 i개의 체커가 모이기 위해 필요한 최소 이동거리

				if (answer[i] == -1) {
					answer[i] = temp;
				}
				else {
					answer[i] = min(answer[i], temp); //answer[i]는 기준 좌표가 바뀌면서 변경될 수 있다
				}
			}
		}
	}

	for (int i : answer) { //n개의 체커가 모이기 위한 최소 이동거리 오름차순 출력
		cout << i << ' ';
	}

	return 0;
}
