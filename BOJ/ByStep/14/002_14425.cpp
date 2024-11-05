#include<iostream>
#include<map>
using namespace std;

map<string, int> mp;
int cnt, n, m;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		mp[s]++;
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		if (mp[s]) cnt++;
	}
	
	cout << cnt;

	return 0;
}

//map은 한번이라도 언급된다면 메모리를 할당하고 value를 0으로 초기화하여 key - value 쌍을 생성합니다
