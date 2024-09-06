#include<iostream>
#include<map>
using namespace std;


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

//map<string, string, greater<>> mp; //사전의 역순 = 내림차순 = greater<> = 큰 것이 먼저
//sort(s.begin(), s.end(), greater<int>()); //큰 것이 먼저
//같은 greater, less지만 표기 방식이 조금 다릅니다!
