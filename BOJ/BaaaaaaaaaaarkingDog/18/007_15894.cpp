#include<iostream>
using namespace std;
typedef unsigned int ui;

ui n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n; // n <= 10^9
	cout << 4 * n; // 4 * (10^9) -> 21억 x 2 이하 -> unsigned int

	return 0;
}
