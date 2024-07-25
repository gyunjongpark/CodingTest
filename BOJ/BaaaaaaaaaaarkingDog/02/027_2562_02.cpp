#include<iostream>
#include<algorithm> //max_element
using namespace std;

int a[9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}

	cout << *max_element(a, a + 9) << '\n';
	cout << max_element(a, a + 9) - a + 1; //iterator - iterator = index

	return 0;
}
