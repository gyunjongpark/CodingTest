#include<iostream>
using namespace std;

int n, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	//백색 깃발이 위로 올라오려면 깃발이 바뀌는 횟수가 홀수여야 한다
	//어떤 수의 제곱근이 자연수라면 그 수는 반드시 홀수 횟수를 가진다
	//제곱근이 자연수이면서 n 이하인 수의 갯수를 계산한다
	for (int i = 1; i * i <= n; i++) {
		ret++;
	}

	cout << ret;

	return 0;
}
