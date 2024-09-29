#include<iostream>
#include<vector>
using namespace std;

int n, m, sum;
int minVal = 10001;
bool chae[10001]; //범위는 넉넉히 잡는다

vector<int> era(int num) { //에라토스테네스의 체
	vector<int> v;

	chae[0] = false;
	chae[1] = false;

	for (int i = 2; i <= num; i++) {
		chae[i] = true;
	}

	//O(Nlog(logN))
	for (int i = 2; i <= num; i++) {
		if (!chae[i]) continue; //이미 지워졌다면 continue

		for (int j = i + i; j <= num; j += i) {
			chae[j] = false; //i를 제외한 i의 배수 지우기
		}
	}

	for (int i = 0; i <= num; i++) {
		if (chae[i]) v.push_back(i); //소수만 골라서 push back
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

	if (sum) cout << sum << '\n' << minVal;
	else cout << -1;

	return 0;
}
