#include<iostream>
using namespace std;

int n, k, s, g, ret, arr[2][6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> s >> g;
    
		arr[s][g - 1]++; //입력받는 g는 1 ~ 6이므로 인덱싱에 주의
		
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] % k) {
				ret += (arr[i][j] / k) + 1;
			}
			else ret += arr[i][j] / k;
		}
	}
  
	cout << ret;

	return 0;
}
