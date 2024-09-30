#include<iostream>
using namespace std;
typedef unsigned long long ll;

ll a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> a >> b;
	
	if (a > b) {
		swap(a, b); //call by reference
	}
  
	if (a == b || b - a == 1) cout << 0;
	else {
		cout << b - a - 1 << '\n';

		for (ll i = a + 1; i < b; i++) {
			cout << i << ' ';
		}
	}

	return 0;
}

/* call-by-reference 생각나는 함수들?
reverse(begin iterator, end iterator);
rotate(begin iterator, begin + range toward counter-wise, end iterator);
swap(a, b);
swap_ranges(a, a+n, b) //a.begin부터 n개의 수를 b의 begin부터 n개까지 바꾼다
max_element(a, a+n) //a.begin부터 n개의 수 중 최대값의 주소를 반환한다
min_element(a, a+n) //a.begin부터 n개의 수 중 최소값의 주소를 반환한다
*/
