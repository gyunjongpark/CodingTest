#include <iostream>
using namespace std;

int i = 1;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n > i) {
		n -= i;
		i++;
	}

	if (i % 2 == 1) {
		cout << i + 1 - n << '/' << n << '\n';
	}	
	else {
		cout << n << '/' << i + 1 - n << '\n';
	}

	return 0;
}

//너무 신박해서 출제될 확률은 희박할 듯...
