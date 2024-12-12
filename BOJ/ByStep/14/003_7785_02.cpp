#include<iostream>
#include<map>
using namespace std;

map<string, string, greater<string>> mp; //사전의 역순 = 내림차순 = greater<자료형> = 큰 것이 먼저
string a, b;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		mp[a] = b;
	}

	for (pair<string,string> s : mp) {
		if (s.second == "enter") {
			cout << s.first << '\n';
		}
	}

	return 0;
}

//map<string, string, greater<string>> mp; //사전의 역순 = 내림차순 = greater<자료형> = 큰 것이 먼저
//sort(s.begin(), s.end(), greater<int>()); //큰 것이 먼저
//같은 greater, less지만 표기 방식이 조금 다릅니다!
//pq, map과 같은 자료구조는 cmp자리에 greater<자료형>이 들어가고, 정렬은 greater<자료형>()이 들어간다. ()추가!
