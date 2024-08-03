#include<iostream>
using namespace std;

int x, n, a, b, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> x >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		sum += a * b;
	}
	
	if (x == sum) cout << "Yes";
	else cout << "No";

    return 0;
}
