#include<iostream>
using namespace std;

int a, b, c, d, e, f;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> a >> b >> c >> d >> e >> f;

  //unique solution in mathematics
	cout << (c * e - b * f) / (a * e - b * d) << ' ' << (c * d - a * f) / (b * d - a * e);

	return 0;
}
