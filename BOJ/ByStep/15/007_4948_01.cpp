#include<iostream>
#include<vector>
using namespace std;

int n;
bool chae[250001]; //n <= 123456이므로 대충 2배인 25만

vector<int> era(int n) {
	vector<int> v;

	chae[0] = false;
	chae[1] = false;

	for (int i = 2; i <= n; i++) {
		chae[i] = true;
	}

	for (int i = 2; i <= n; i++) {
		if (!chae[i]) continue; //이미 지워졌다면 continue

		for (int j = i + i; j <= n; j += i) {
			chae[j] = false; //i의 배수 지우기(소수만 남기기)
		}
	}

	for (int i = 2; i <= n; i++) {
		if (chae[i]) v.push_back(i); //소수라면 push back
	}

	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		vector<int> ret;

		cin >> n;

		if (n == 0) break;

		vector<int> v = era(2 * n);

		for (int i : v) {
			if (i > n) {
				ret.push_back(i);
			}
		}

		cout << ret.size() << '\n';
	}

	return 0;
}
