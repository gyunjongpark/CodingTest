#include<iostream>
#include<vector>
#define MAX 300004 // n <= 123456
using namespace std;

int n, chae[MAX];
vector<int> v;

vector<int> era(int n) {
	vector<int> v;

	for (int i = 2; i <= n; i++) {
		if (chae[i]) continue; //이미 지워졌다면 continue

		for (int j = i + i; j <= n; j += i) {
			chae[j] = 1; //i의 배수 지우기(소수만 남기기)
		}
	}

	for (int i = 2; i <= n; i++) {
		if (!chae[i]) v.push_back(i); //소수라면 push back
	}

	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		v.clear(); //init

		cin >> n;
		if (n == 0) break;

		vector<int> ret = era(2 * n);

		for (int i : ret) {
			if (i > n) {
				v.push_back(i);
			}
		}
		cout << v.size()<<'\n';
	}

	return 0;
}
