#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, m, a[51][51];
int ret_city_dist = INT_MAX; //도시의 치킨 거리의 최솟값 계산
vector<pair<int, int>> house, chicken_store; //집 목록, 치킨집 목록

int calculate_city_distance(vector<pair<int, int>>& house, vector<int>& selected) {
	int city_dist = 0; //도시의 치킨 거리

	for (pair<int, int> home : house) {
		int individual_dist = INT_MAX; //치킨 거리의 최솟값 계산

		for (int selected_number : selected) {
			int abs_y = abs(home.first - chicken_store[selected_number].first);
			int abs_x = abs(home.second - chicken_store[selected_number].second);

			individual_dist = min(individual_dist, abs_y + abs_x);
		}

		city_dist += individual_dist;
	}

	return city_dist;
}

void combi(int start, vector<int>& selected, vector<bool>& visited) {
	if (selected.size() == m) {
		ret_city_dist = min(ret_city_dist, calculate_city_distance(house, selected));
		return;
	}

	for (int i = start + 1; i < chicken_store.size(); i++) {
		if (visited[i]) continue;

		selected.push_back(i);
		visited[i] = true;

		combi(i, selected,visited);

		selected.pop_back();
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
				house.push_back({ i,j });
			}
			else if (a[i][j] == 2) {
				chicken_store.push_back({ i,j });
			}
		}
	}

	vector<int> selected; //치킨집을 선택하는 경우의 수 저장
	vector<bool> visited(2501, false); //중복 방지를 위한 visited

	combi(-1, selected, visited); //인덱스 연산

	cout << ret_city_dist;

	return 0;
}
