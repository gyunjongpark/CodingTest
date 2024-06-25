#include<iostream>
#include<cmath> //pow
using namespace std;

int n, dot = 2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	cout << (int)pow((int)pow(dot, n) + 1,2);

	return 0;
}
