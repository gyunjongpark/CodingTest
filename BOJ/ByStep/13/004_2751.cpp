#include<iostream>
#include<algorithm> //sort
#include<vector>
using namespace std;

vector<int> v;
int n, temp;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		
		v.push_back(temp);
	}
	
	sort(v.begin(), v.end());

	for (int i : v) cout << i << '\n';

	return 0;
}
