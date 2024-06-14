#include<iostream>
using namespace std;

int a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> a;

	for (int i = 1; i <= 9; i++) {
		cout << a << " * " << i << " = " << a * i << '\n';
	}

    return 0;
}
