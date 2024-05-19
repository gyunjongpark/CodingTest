#include<iostream>
using namespace std;
typedef long long ll;

int n;
ll s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> s;
		bool flag = 1;

		for (int i = 2; i <= 1000000; i++) {
			if (s % i == 0) {
				cout << "NO\n";
				flag = 0;
				break;
			}
		}

		if (flag) cout << "YES\n";
	}

	return 0;
}

/*
어떤 문제든지, 경우의 수가 보인다면
시간과 메모리가 충분히 주어진다면
완전탐색으로 그 문제를 해결할 수 있다.
모든 경우의 수를 넣고
조건문으로 걸러내주면 정답을 찾을 수 있다.
*/
