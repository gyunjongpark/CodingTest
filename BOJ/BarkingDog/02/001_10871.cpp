#include<iostream>
#include<vector>
using namespace std;

int n, x, temp;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> temp;
    
		if (temp < x) v.push_back(temp);
	}

	for (int i : v) cout << i << ' ';

	return 0;
}
