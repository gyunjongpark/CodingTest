#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, m, cnt, a[15001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//고유한 번호 a[i]는 10만 이하, 따라서 2개의 재료는 20만 이하
	if (m > 200000) {
		cout << 0; //20만 이상은 불가능하므로 0개 출력
	}
	else {
		sort(a, a + n);

		//two pointer
		int start = 0; int end = n - 1;
		while (start < end) {
			int sum = a[start] + a[end];

			if (sum == m) {
				cnt++;

				//각각 고유한 번호를 가지고 있으므로 start,end 모두 조절
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
