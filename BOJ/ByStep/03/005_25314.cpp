#include<iostream>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n / 4; i++) {
		cout << "long ";
	}
	
	cout << "int";

    return 0;
}
