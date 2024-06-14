#include<iostream>
using namespace std;

int x, y, w, h;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y >> w >> h;
	int dist_x = min(x, w - x);
	int dist_y = min(y, h - y);

	cout << min(dist_x, dist_y);

	return 0;
}
