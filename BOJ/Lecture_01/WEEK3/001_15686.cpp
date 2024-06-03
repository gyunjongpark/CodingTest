#include<iostream>
#include<vector>
#define MAX 51
using namespace std;

int n, m, a[MAX][MAX];
vector<pair<int, int>> home, chicken; //집, 치킨집 좌표 저장
vector<vector<int>> chickenList; //선택한 치킨집 리스트 저장

void combi(int start, vector<int> v) {
	if (v.size() == m) { //m개를 골랐다면
		chickenList.push_back(v); //치킨집 리스트에 저장

		return;
	}

	for (int i = start + 1; i < chicken.size(); i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
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
			if (a[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	vector<int> v; //치킨집 리스트 저장을 위한 vector
	combi(-1, v); //치킨집 중에 m개를 선택해서 v에 저장 후 chickenList에 v를 저장

	int ret = 1e6; //도시의 치킨 거리의 최소값 구하기
	for (vector<int> cList : chickenList) {
		int dist_city = 0; //도시의 치킨 거리
		for (pair<int, int> _home : home) {
			int dist = 1e6; //치킨 거리의 최소값 구하기
			for (int ch : cList) {
				int abs_first = abs(_home.first - chicken[ch].first);
				int abs_second = abs(_home.second - chicken[ch].second);
				int _dist = abs_first + abs_second; //치킨 거리

				dist = min(dist, _dist); //치킨 거리의 최소값이 최종 치킨 거리가 된다
			}
			dist_city += dist; //도시의 치킨 거리는 최종 치킨 거리의 합
		}
		ret = min(ret, dist_city); //도시의 치킨 거리의 최소값이 최종 도시의 치킨 거리가 된다
	}
	cout << ret; //최종 도시의 치킨 거리 출력

	return 0;
}
