#include <iostream>
using namespace std;

int a, b, v;
int day = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> v;

	day += (v - a) / (a - b);

	if ((v - a) % (a - b)){
		day++;
	}

	cout << day;

	return 0;
}
