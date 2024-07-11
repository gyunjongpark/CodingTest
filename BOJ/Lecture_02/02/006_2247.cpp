#include<iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int answer = 0;

	//n은 최대 2억 -> 시간제한 2초
	for (int i = 2; i <= n; i++) { //1을 제외한 i로 cnt를 계산한다(실질적 약수)
		int cnt = n / i;
		//n!에서 i가 몇 개 있는가?(i를 약수로 가지는 개수가 몇 개인가?)
		//단, 증감문이 i++이므로 i의 승수들은 무시한다(4, 8, 16...)
		
		answer += (cnt - 1) * i;
		//i 본인을 제외한(실질적 약수) 개수와 i를 곱하면 csod(n)에서 i가 차지하는 누적값을 구할 수 있다
		//i가 증가함에 따라 모든 i에 따른 누적값의 합을 answer에 추가하면서 최종적인 csod(n)를 완성한다
		
		answer %= 1000000; //i가 증가할 때마다 모듈 연산. 자료형 메모리 초과 방지
	}
	cout << answer;

	return 0;
}
