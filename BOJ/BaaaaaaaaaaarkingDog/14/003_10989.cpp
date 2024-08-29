#include<iostream>
using namespace std;

int n, temp, a[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		a[temp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < a[i]; j++) {
			cout << i << '\n';
		}
	}

	return 0;
}

//counting sort : O(입력될 수의 갯수N + 수의 최댓값 K)로 N과 K가 비슷하다면 O(N)의 시간복잡도를 가진다
//하지만 메모리 초과를 생각해야 한다(K가 높다면 사용할 수 없다).
