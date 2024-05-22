#include<iostream>
#include<algorithm>
using namespace std;

int n, m, cnt, a[15001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (m > 200000) {
		cout << 0;
	}
	else {
		sort(a, a + n);

		//two pointer
		int start = 0; int end = n - 1;
		while (start < end) {
			int sum = a[start] + a[end];
			
			if (sum == m) {
				cnt++;
				start++;
				end--;
			}
			else if (sum > m) {
				end--;
			}
			else {
				start++;
			}
		}
		cout << cnt;
	}
  
	return 0;
}
