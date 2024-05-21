#include<iostream>
using namespace std;

string s;
int cnt[101];
int a, b, c, d, e, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;

	for (int i = 0; i < 3; i++) { //트럭은 3대로 정해져 있음
		cin >> d >> e;
		
		for (int j = d; j < e; j++) {
			cnt[j]++;
		}
	}

	for (int i = 1; i <= 100; i++) {
		if (cnt[i] == 1) ret += a;
		else if (cnt[i] == 2) ret += 2 * b;
		else if (cnt[i] == 3) ret += 3 * c;
	}
	cout << ret;

	return 0;
}
