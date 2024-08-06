#include<iostream>
using namespace std;

int h, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> h >> m;

	int temp = h * 60 + m - 45;

	if (temp < 0) {
		temp += 24 * 60;
	}
	
	h = temp / 60, m = temp % 60;
	
	cout << h << ' ' << m;

    return 0;
}
