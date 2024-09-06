#include<iostream>
#include<algorithm> //lower_bound, upper_bound
#include<vector>
using namespace std;

int n, temp;
vector<int> v, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		
		v.push_back(temp);
		ret.push_back(temp);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	//lower(upper)_bound(시작 이터레이터, 끝 이터레이터, 찾는 값) -> 이터레이터를 반환하므로 적절한 연산 필요
	for (int i = 0; i < n; i++) {
		cout << lower_bound(v.begin(), v.end(), ret[i]) - v.begin() << ' ';
	}

	return 0;
}
