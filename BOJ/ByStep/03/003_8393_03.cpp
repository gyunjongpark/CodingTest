#include<iostream>
using namespace std;

int n, sum, s[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + i;
	}
	
	cout << s[n];

    return 0;
}
