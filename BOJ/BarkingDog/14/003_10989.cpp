#include<iostream>
using namespace std;

int a[10001], n, temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		a[temp]++;
	}
  
  //counting sort
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < a[i]; j++) {
			cout << i << '\n';
		}
	}

	return 0;
}
