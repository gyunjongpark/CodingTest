#include<iostream>
#include<algorithm> //reverse
using namespace std;

string a, b;

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> a >> b;
    
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
    
	if (a > b) cout << a;
	else cout << b;

	return 0;
}
