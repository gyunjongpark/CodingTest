#include<iostream>
#include<deque>
using namespace std;

deque<int> dq;
int n, m, cnt, val, pos;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		dq.push_back(i + 1);
	}

	for (int i = 0; i < m; i++) {
		cin >> val;

		for (int j = 0; j < dq.size(); j++) {
			if (dq[j] == val) {
				pos = j;
			}
		}

		if (val == dq.front()) {
			dq.pop_front();
		}
		else if (pos <= dq.size() / 2) {
			while (val != dq.front()) {
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++; //2번 연산
			}

			dq.pop_front();
		}
		else if (pos > dq.size() / 2) { //pos가 정중앙일 경우 val 본인도 이동해야하므로 등호는 2번 연산에 붙인다
			while (val != dq.front()) {
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++; //3번 연산. 
			}

			dq.pop_front();
		}
	}

	cout << cnt;

	return 0;
}
