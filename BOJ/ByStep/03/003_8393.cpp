#include<iostream>
#define MAX 10004
using namespace std;

int n, sum, psum[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + i;
	}
	cout << psum[n];

    return 0;
}
