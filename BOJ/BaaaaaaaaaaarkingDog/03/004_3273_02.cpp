#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, x, ret, a[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a, a + n); //O(NlogN)

	cin >> x;

	//two pointer, O(N)
	int l = 0, r = n - 1;

	while (l < r) {
		if (a[l] + a[r] == x) {
			ret++;

			//n개의 서로 다른 양의 정수이므로 두 변수 모두 조정
			l++;
			r--;
		}
		else if (a[l] + a[r] < x) l++;
		else if (a[l] + a[r] > x) r--;
	}
	cout << ret;

	return 0;
}
