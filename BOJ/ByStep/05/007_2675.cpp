#include<iostream>
using namespace std;

int r, t;
string s;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> t;

	while (t--) {
		cin >> r >> s;
    
		for (char a : s) {
			for (int i = 0; i < r; i++) {
				cout << a;
			}
		}
		cout << '\n';
	}

	return 0;
}
