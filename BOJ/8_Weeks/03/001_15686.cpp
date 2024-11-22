#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, m, a[51][51];
int ret = INT_MAX; //도시의 치킨 거리 중 최솟값 계산
vector<pair<int, int>> home, chicken; //집 목록, 치킨집 목록

int cal_city_dist(vector<pair<int, int>>& home, vector<int>& v) {
	int city_dist = 0;

	for (pair<int, int> h : home) {
		int dist = INT_MAX; //하나의 집에서 가까운 치킨집과의 거리 계산

		for (int selected_number : v) {
			int abs_y = abs(h.first - chicken[selected_number].first);
			int abs_x = abs(h.second - chicken[selected_number].second);

			dist = min(dist, abs_y + abs_x);
		}

		city_dist += dist; //전체 합산
	}

	return city_dist; //도시의 치킨 거리 반환
}

void combi(int start, vector<int>& v, vector<bool>& visited) {
	if (v.size() == m) { //m개를 방문한다면
		ret = min(ret, cal_city_dist(home, v));
		return;
	}

	for (int i = start + 1; i < chicken.size(); i++) {
		if (visited[i]) continue; //중복 방지

		v.push_back(i);
		visited[i] = true;

		combi(i, v, visited);

		v.pop_back();
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

	vector<int> v; //치킨집 번호 저장
	vector<bool> visited(2501, false); //방문 처리

	combi(-1, v, visited);

	cout << ret;

	return 0;
}
