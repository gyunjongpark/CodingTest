#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int n, a, b, c;
string s;
vector<pair<string, pair<pair<int, int>, int>>> v;

bool cmp(pair<string, pair<pair<int, int>, int>> a, pair<string, pair<pair<int, int>, int>> b) {
	if (a.second.first.first == b.second.first.first) { //국어 점수가 같다면
		if (a.second.first.second == b.second.first.second) { //국어, 영어 점수가 같다면
			if (a.second.second == b.second.second) { //국어, 영어, 수학 점수가 같다면
				return a.first < b.first; //이름으로 비교
			}
			else { //국어, 영어는 같지만 수학 점수가 다르다면
				return a.second.second > b.second.second;
			}
		}
		else return a.second.first.second < b.second.first.second; //국어는 같지만 영어점수가 다르다면
	}
	else return a.second.first.first > b.second.first.first; //국어 점수가 다르다면
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s >> a >> b >> c; //이름, 국어, 영어, 수학
		v.push_back({ s,{{a,b},c} });
	}

	sort(v.begin(), v.end(), cmp);

	for (pair<string, pair<pair<int, int>, int>> i : v) {
		cout << i.first << '\n';
	}

	return 0;
}
