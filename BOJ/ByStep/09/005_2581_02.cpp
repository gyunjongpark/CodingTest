#include<iostream>
#include<vector>
#define MAX 10004
using namespace std;

int n, m, sum, minVal = MAX, chae[MAX];

vector<int> era(int n) {
	vector<int> v;

	for (int i = 2; i <= n; i++) {
		if (chae[i]) continue; // 이미 지워졌다면 continue
		for (int j = i + i; j <= n; j += i) {
			chae[j] = 1; // i의 배수 지우기(소수만 남기기)
		}
	}

	for (int i = 2; i <= n; i++) {
		if (!chae[i]) v.push_back(i); // 소수라면 push back
	}

	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;

	vector<int> ret = era(n);

	for (int i : ret) {
		if (i >= m) {
			sum += i;
			minVal = min(minVal, i);
		}
	}
	if (sum) cout << sum<<'\n'<<minVal;
	else cout << -1;

	return 0;
}
