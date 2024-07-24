#include<iostream>
#include<algorithm> //sort, erase, unique
#include<vector>
using namespace std;

vector<int> a;
int n;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 10; i++) {
		cin >> n;
		a.push_back(n % 42);
	}

	sort(a.begin(), a.end());
	
	a.erase(unique(a.begin(), a.end()), a.end());

	cout << a.size();

	return 0;
}
