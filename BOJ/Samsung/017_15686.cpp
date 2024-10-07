#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, m, a[51][51];
int ret_city_dist = INT_MAX; //도시의 치킨 거리의 최솟값 계산
vector<pair<int, int>> house, chicken_store; //집 목록, 치킨집 목록
vector<int> selected_chicken_store_number; //치킨집을 선택하는 경우의 수 저장

int calculate_city_distance(vector<pair<int, int>>& house, vector<int>& selected_chicken_store_number) {
	int city_dist = 0; //도시의 치킨 거리

	for (pair<int, int> home : house) {
		int individual_dist = INT_MAX; //치킨 거리의 최솟값 계산

		for (int selected_number : selected_chicken_store_number) {
			int abs_first = abs(home.first - chicken_store[selected_number].first);
			int abs_second = abs(home.second - chicken_store[selected_number].second);

			individual_dist = min(individual_dist, abs_first + abs_second);
		}

		city_dist += individual_dist;
	}

	return city_dist;
}

void combi(int start, vector<int>& selected_chicken_store_number) {
	if (selected_chicken_store_number.size() == m) {
		ret_city_dist = min(ret_city_dist, calculate_city_distance(house, selected_chicken_store_number));

		return;
	}

	for (int i = start + 1; i < chicken_store.size(); i++) {
		selected_chicken_store_number.push_back(i);

		combi(i, selected_chicken_store_number);

		selected_chicken_store_number.pop_back();
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

	combi(-1, selected_chicken_store_number);

	cout << ret_city_dist;

	return 0;
}
