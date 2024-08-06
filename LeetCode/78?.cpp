#include<iostream>
#include<vector>
using namespace std;

int n, a[101];
vector<int> v;

void print(vector<int>& v) {
	if (v.empty()) {
		cout << "[]";
    
		return;
	}

	cout << "[";
	
	for (int i = 0; i < v.size() - 1; i++) {
		cout << v[i] << ", ";
	}
	cout << v[v.size() - 1] << "]";
  
	return;
}

void combi(int start, vector<int>& v, int k) {
	if (v.size() == k) {
		print(v);

		return;
	}

	for (int i = start + 1; i < n; i++) {
		v.push_back(a[i]);
		combi(i, v, k);
		v.pop_back();
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}

	for (int k = 0; k <= n; k++) {
		combi(-1, v, k);
		cout << '\n';
	}

	return 0;
}
