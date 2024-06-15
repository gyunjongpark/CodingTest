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
		answer += (cnt - 1) * i; //본인 제외 i의 곱을 합하면 sod
		answer %= 1000000;
	}
	cout << answer;

	return 0;
}
