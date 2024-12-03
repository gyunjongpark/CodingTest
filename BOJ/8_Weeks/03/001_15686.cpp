#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, m, a[51][51];
int ret = INT_MAX; //도시의 치킨 거리 중 최솟값 계산
vector<pair<int, int>> home, chicken; //집, 치킨집의 좌표 저장

int cal_city_dist(vector<pair<int, int>>& home, vector<int>& ch_idx) {
	int city_dist = 0;

	for (pair<int, int> h : home) {
		int dist = INT_MAX; //각각의 집마다 가까운 치킨집과의 거리 계산

		for (int selected_number : ch_idx) {
			int abs_y = abs(h.first - chicken[selected_number].first);
			int abs_x = abs(h.second - chicken[selected_number].second);

			dist = min(dist, abs_y + abs_x);
		}

		city_dist += dist; //전체 합산
	}

	return city_dist;
}

void combi(int start, vector<int>& ch_idx, vector<bool>& visited) {
	if (ch_idx.size() == m) {
		ret = min(ret, cal_city_dist(home, ch_idx));
		return;
	}

	for (int i = start + 1; i < chicken.size(); i++) { //전체 치킨집 중 m개 선택
		if (visited[i]) continue;

		ch_idx.push_back(i);
		visited[i] = true;

		combi(i, ch_idx, visited);

		ch_idx.pop_back();
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];

			if (a[i][j] == 1) {
				home.push_back({ i,j });
			}
			else if (a[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	vector<int> ch_idx; //치킨집 번호 저장
	vector<bool> visited(2501, false); //방문 처리

	combi(-1, ch_idx, visited);

	cout << ret;

	return 0;
}
