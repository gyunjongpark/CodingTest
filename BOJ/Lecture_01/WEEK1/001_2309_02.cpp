#include<iostream>
#include<algorithm>
using namespace std;

int a[9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}

	sort(a, a + 9); //정렬 필수

	//7명을 순열로 뽑고 무작정 더하기
	do {
		int sum = 0;
		for (int i = 0; i < 7; i++) { 
			sum += a[i];
		}
		if (sum == 100) break; //조건 만족 시 탈출
	} while (next_permutation(a, a + 9));
	
	//순열의 결과가 배열에 그대로 유지된다
	for (int i = 0; i < 7; i++) cout << a[i] << '\n';

	return 0;
}
