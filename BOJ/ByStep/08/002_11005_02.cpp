#include<iostream>
#include<vector>
#include<algorithm> //reverse
using namespace std;

int n, b;
vector<int> v;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> b;

	while (n > 1) {
		v.push_back(n % b);
		n /= b;
	}
	if (n == 1) v.push_back(n);
  
	reverse(v.begin(), v.end());
	
	for (int a : v) {
		if (a >= 10) cout << char(a + 55); //아스키 코드 참고
		else cout << a;
	}

	return 0;
}
