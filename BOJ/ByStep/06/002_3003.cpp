#include<iostream>
using namespace std;

int a[6] = { 1,1,2,2,2,8 }, temp;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	
	for (int i = 0; i < 6; i++) {
		cin >> temp;
		a[i] -= temp;
	}

	for (int i = 0; i < 6; i++) {
		cout << a[i]<<' ';
	}
  
	return 0;
}
