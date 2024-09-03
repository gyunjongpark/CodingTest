#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, m, a[51][51];
int ret_hospital_dist = INT_MAX; //최종적인 병원 거리 계산
vector<pair<int, int>> house, hospital_list; //집 목록, 병원 목록
vector<int> selected_hospital_number_list; //병원을 선택하는 경우의 수 저장

int calculate_distance(vector<pair<int, int>>& house, vector<int>& selected_hospital_number_list) {
	int hosp_dist = 0; //병원 목록이 정해졌을 때 병원 거리 계산하기

	for (pair<int, int> home : house) {
		int individual_dist = INT_MAX; //개인적인 병원 거리의 최솟값 계산하기

		for (int selected_number : selected_hospital_number_list) {
			individual_dist = min(individual_dist, abs(home.first - hospital_list[selected_number].first) + abs(home.second - hospital_list[selected_number].second));
		}

		hosp_dist += individual_dist;
	}

	return hosp_dist;
}

void combi(int start, vector<int>& selected_hospital_number_list) {
	if (selected_hospital_number_list.size() == m) {
		ret_hospital_dist = min(ret_hospital_dist, calculate_distance(house, selected_hospital_number_list));

		return;
	}

	for (int i = start + 1; i < hospital_list.size(); i++) {
		selected_hospital_number_list.push_back(i);

		combi(i, selected_hospital_number_list);

		selected_hospital_number_list.pop_back(); //원상 복구
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
				hospital_list.push_back({ i,j });
			}
		}
	}

	combi(-1, selected_hospital_number_list);

	cout << ret_hospital_dist;

	return 0;
}
