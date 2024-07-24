#include<iostream>
#include<vector>
using namespace std;

int n, temp, total, ret;
vector<int> v, d;

int getGCD(int a, int b) {
	if (a == 0) return b;
	return getGCD(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp); // 현재 가로수 위치
	}

	for (int i = 0; i < n - 1; i++) {
		d.push_back(v[i + 1] - v[i]); // 가로수 사이 거리, d[0]~d[n-2]
	}

	int dist = d[0]; //초기화, v[1]-v[0]
	for (int i = 1; i < n - 1; i++) {
		dist = getGCD(dist, d[i]); // 최소 거리 구하기
	}

	total = v[n - 1] - v[0]; // 전체 거리의 길이
	ret = total / dist; // 목표 가로수의 개수 구하기
	ret -= n - 1; // 이미 심어져 있는 가로수들 제외

	cout << ret;

	return 0;
}
