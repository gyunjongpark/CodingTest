#include<iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int answer = 0;

	// 문제에서 n은 최대 2억 -> 시간제한 2초
	for (int i = 2; i <= n; i++) { // 실질적 약수이므로 1을 제외한 i로 cnt를 계산한다 (1 제외)
		int cnt = n / i; // n!에서 i를 일반적인 약수로 가지는 개수가 몇 개인가?
		
		answer += (cnt - 1) * i; // (본인 제외)
		// 실질적 약수는 일반적인 약수에서 1과 본인을 제외한다
		// i 본인을 제외한 cnt와 i를 곱하면 csod(n)에서 i가 차지하는 누적값을 구할 수 있다
		// i가 증가함에 따라 i에 따른 누적값의 합을 answer에 추가하면서 최종적으로 csod(n)를 완성한다
		
		answer %= 1000000; // i가 증가할 때마다 모듈 연산. 자료형 메모리 초과 방지
	}
	cout << answer;

	return 0;
}