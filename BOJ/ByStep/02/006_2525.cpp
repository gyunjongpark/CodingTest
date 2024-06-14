#include<iostream>
using namespace std;

int h, m, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> h >> m >> t;

	int temp = h * 60 + m + t;
	h = temp / 60, m = temp % 60;

	if (h > 23) {
		h -= 24;
	}

	cout << h << ' ' << m;

    return 0;
}
