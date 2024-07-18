#include<iostream>
#include<list>
using namespace std;

list<int> L;
int n, k;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		L.push_back(i);
	}
	
	cout << "<";
	while (true) {
		if (L.size() == 1) {
			cout << L.front();

			break;
		}

		for (int i = 0; i < k - 1; i++) {
			L.push_back(L.front());
			L.pop_front();
		}

		cout <<L.front() << ", ";
		L.erase(L.begin());
	}
	cout << ">";

	return 0;
}
