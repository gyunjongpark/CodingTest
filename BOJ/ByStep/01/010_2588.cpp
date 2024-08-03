#include<iostream>
using namespace std;

int a, b, ret1, ret2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	cout << a * (b % 10) << '\n';
	cout << a * ((b / 10) % 10) << '\n';
	cout << a * (b / 100) << '\n';
	
	ret1 = a * (b % 10) + 10 * (a * ((b / 10) % 10));
	ret2 = 100 * (a * (b / 100));
	
	cout << ret1 + ret2;

    return 0;
}
