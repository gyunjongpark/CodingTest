#include<iostream>
#include<list>
using namespace std;

list<int> L;
int n, k;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		L.push_back(i + 1);
	}

	int cur = k;

	cout << '<';

	while (true) {
		if (L.size() == 1) {
			cout << L.front();
			break;
		}

		for (int i = 0; i < cur - 1; i++) {
			L.push_back(L.front());
			L.pop_front();
		}

		cout << L.front() << ", ";

		L.pop_front();
	}

	cout << '>';

	return 0;
}
