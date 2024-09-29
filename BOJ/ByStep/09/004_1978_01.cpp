#include<iostream>
#include<cmath> //sqrt
using namespace std;

int a, n, ret;

bool check(int n) {
	if (n <= 1) return 0;
	
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) return 0;
	}
  
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		
		if (check(a)) ret++;
	}
  
	cout << ret;

	return 0;
}
