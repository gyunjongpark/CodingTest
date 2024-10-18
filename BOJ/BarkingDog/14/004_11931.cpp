#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int n, temp;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	//N은 10 ^ 6이므로 O(NlogN) 내의 정렬 방식을 사용해야 한다
	sort(v.begin(), v.end(), greater<int>());

	for (int i : v) cout << i << '\n';

	return 0;
}
