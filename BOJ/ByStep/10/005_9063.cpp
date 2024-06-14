#include<iostream>
#define MAX 10004
using namespace std;

int n, x, y;
int maxX = -MAX, maxY = -MAX;
int minX = MAX, minY = MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		maxX = max(x, maxX); maxY = max(y, maxY);
		minX = min(x, minX); minY = min(y, minY);
	}
	cout << (maxX - minX) * (maxY - minY);

	return 0;
}
