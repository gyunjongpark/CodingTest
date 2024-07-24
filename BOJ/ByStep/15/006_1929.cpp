#include<iostream>
#include<vector>
using namespace std;

int n, m, sum, chae[1000001];
vector<int> v;

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
		if (i >= m) v.push_back(i);
	}
	
	for (int i : v) cout << i << '\n';

	return 0;
}
