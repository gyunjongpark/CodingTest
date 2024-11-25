#include<iostream>
#include<map>
using namespace std;

int n, m, temp;
map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	//맵은 기본적으로 이진 탐색 트리 방식
	//삽입, 삭제, 수정, 탐색 전부 (O(logN))
	for (int i = 0; i < n; i++) {
		cin >> temp;
		mp[temp]++;
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> temp;
		
		if (mp[temp]) cout << 1 << ' ';
		else cout << 0 << ' ';
	}

	return 0;
}
