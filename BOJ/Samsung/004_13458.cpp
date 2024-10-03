#include<iostream>
using namespace std;
typedef unsigned long long ll;

int n, a[1000001], leader, teammate;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n; //시험장 수

	for (int i = 0; i < n; i++) {
		cin >> a[i]; //응시자 수
	}

	cin >> leader >> teammate; //감독관 최대 할당량, 부감독관 최대 할당량

	ll ret = n;
	
	for (int i = 0; i < n; i++) {
		if (a[i] <= leader) continue;

		a[i] -= leader;
		ret += a[i] / teammate;

		if (a[i] % teammate) ret += 1;
	}

	cout << ret;

	return 0;
}
