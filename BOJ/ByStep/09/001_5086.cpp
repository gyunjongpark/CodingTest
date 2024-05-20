#include <iostream>
using namespace std;

int a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> a >> b;

		if (a == 0 && b == 0) break;
		
		if (b % a == 0) cout << "factor\n";
		else if (a % b == 0) cout << "multiple\n";
		else cout << "neither\n";
	}
	
	return 0;
}
