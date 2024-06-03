#include<iostream>
#include<vector>
#define MAX 51
using namespace std;

int n, m, a[MAX][MAX];
vector<pair<int, int>> home, chicken;
vector<vector<int>> chickenList;

void combi(int start, vector<int> v) {
	if (v.size() == m) { //m개를 골랐다면
		chickenList.push_back(v);
		return;
	}

	for (int i = start + 1; i < chicken.size(); i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back(); //원상 복구
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) home.push_back({ i,j });
			else if (a[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	vector<int> v; //치킨집 고르는 순서 저장
	combi(-1, v);

	int dist_chicken = 1e6;
	for (vector<int> cList : chickenList) {
		int dist_city = 0; //도시의 치킨 거리
		for (pair<int, int> _home : home) {
			int dist = 1e6; //치킨 거리
			for (int ch : cList) {
				int abs_first = abs(_home.first - chicken[ch].first);
				int abs_second = abs(_home.second - chicken[ch].second);
				int _dist = abs_first + abs_second;

				dist = min(dist, _dist); //거리의 최소값이 최종 치킨 거리가 된다
			}
			dist_city += dist; //도시의 치킨 거리는 치킨 거리의 합
		}
		dist_chicken = min(dist_chicken, dist_city); //가장 작은 도시의 치킨 거리
	}
	cout << dist_chicken;

	return 0;
}
