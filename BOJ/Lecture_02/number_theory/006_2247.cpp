#include<iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int answer = 0;

	//n은 최대 2억 -> 시간제한은 2초
	for (int i = 2; i <= n; i++) {
		int cnt = n / i; //i를 약수로 가지는 수의 갯수
		answer += (cnt - 1) * i; //본인을 제외한 갯수와 i의 곱의 총 합은 csod
		answer %= 1000000; //루프마다 나머지 계산해서 메모리 맞추기
	}
	cout << answer;

	return 0;
}
