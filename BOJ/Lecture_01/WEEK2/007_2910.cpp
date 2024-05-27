#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#define MAX 1001
using namespace std;

int n, c, a[MAX];
map<int, int> mp, mp2;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) { //나온 횟수가 같다면
		return mp2[a.first] < mp2[b.first]; //먼저 나온 순서대로
	}
  
	return a.second > b.second; //많이 나온 순서대로
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++; //mp : 배열의 값 - 값이 나온 횟수 저장
		if (mp2[a[i]] == 0) //mp2 : 배열의 값 - 값이 나온 순서 저장
			mp2[a[i]] = i + 1;
	}

	for (pair<int, int> pi : mp) {
		v.push_back(pi);
	}
	sort(v.begin(), v.end(), cmp);

	for (pair<int, int> pi : v) {
		for (int i = 0; i < pi.second; i++) {
			cout << pi.first << ' ';
		}
	}

	return 0;
}
