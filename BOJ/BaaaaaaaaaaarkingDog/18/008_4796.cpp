#include<iostream>
using namespace std;

int l, p, v;
int cnt = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> l >> p >> v;

		if (l == 0 && p == 0 && v == 0) break;

		int use = v / p;
		int remain = v % p;

		if (l < remain) remain = l;

		int ret = l * use + remain;

		cout << "Case " << cnt << ": " << ret << '\n';
    
		cnt++;
	}

	return 0;
}
