#include<iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int answer = 0;

	//n은 최대 2억 -> 시간제한 2초
	for (int i = 2; i <= n; i++) { //1을 제외하고 i부터 계산(실질적 약수)
		int cnt = n / i; //n!에서 i가 몇 개 있는가?
		answer += (cnt - 1) * i;
		//i 본인을 제외한(실질적 약수) 갯수와 i를 곱하면 csod(n)에서 i가 나온 횟수를 구할 수 있다
		//i가 증가함에 따라 최종적인 csod(n)을 answer로 값을 누적하면서 구할 수 있게 된다
		
		answer %= 1000000; //메모리 초과 방지
	}
	cout << answer;

	return 0;
}
