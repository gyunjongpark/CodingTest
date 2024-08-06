#include<iostream>
#include<algorithm> //sort
using namespace std;

int a[5], sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}

	sort(a, a + 5);

	for (int i : a) {
		sum += i;
	}

	cout << sum / 5 << '\n' << a[2];

	return 0;
}
