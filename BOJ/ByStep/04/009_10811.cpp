#include<iostream>
#include<algorithm> //reverse
#include<vector>
using namespace std;

vector<int> v;
int a, b, n, m;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		v.push_back(i+1);
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		
		reverse(v.begin() + a - 1, v.begin() + b); //iterator 연산이므로 begin, end를 기반한 연산이 필요하다
	}
	
	for (int i : v) cout << i << ' ';
	
	return 0;
}
