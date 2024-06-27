#include<iostream>
#include<deque>
using namespace std;

deque<pair<int, int>> dq;
int n, temp, cur;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		dq.push_back({ i + 1,temp });
	}

	while (dq.size()) {
		cout << dq.front().first << ' ';
		cur = dq.front().second;
		dq.pop_front();

		if (dq.empty()) break;

		//cur 위치 신경쓰자!
		if (cur >= 0) {
			for (int i = 0; i < cur - 1; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			for (int i = 0; i < -cur; i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}

	return 0;
}
