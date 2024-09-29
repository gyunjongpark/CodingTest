#include<iostream>
using namespace std;

int n, x, y;
int maxX = -10001, maxY = -10001;
int minX = 10001, minY = 10001;

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
