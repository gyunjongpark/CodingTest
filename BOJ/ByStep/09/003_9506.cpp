#include<iostream>
#include<vector>
using namespace std;

int n, sum;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		sum = 0; v.clear(); //init

		cin >> n;

		if (n == -1) break;

		for (int i = 1; i < n; i++) {
			if (n % i == 0) v.push_back(i);
		}

		for (int i : v) sum += i;

		if (sum == n) {
			cout << n << " = ";
			for (int i = 0; i < v.size() - 1; i++) {
				cout << v[i] << " + ";
			}
			cout << v[v.size()-1] << '\n';
		}
		else cout << n << " is NOT perfect.\n";
	}

	return 0;
}
