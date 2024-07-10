#include<iostream>
using namespace std;
typedef long long ll;

/* 정수론 문제가 나온다면 떠올리면 좋을 반복문

for (int i = a; i <= N; i *= a) {
	ret=N/i; //N!에서 a가 몇 번 곱해져있는가?
}

*/

ll a, b;

ll solve(ll N) { //1부터 N까지 각각의 수가 나눠질 수 있는 2의 최대 승수를 구해서 더함
	ll ret = N;

	for (ll i = 2; i <= N; i *= 2) {
		ret += (N / i) * (i / 2);
	}

	return ret;
}

/*
작은 범위에서 수를 나열해보고 규칙을 찾아낸다
2로 나눌 수 있을까? 나머지는 어떻게 처리할까? 차이는 왜 발생하는 걸까?
결국은 연필과 종이로 규칙성을 코드로 옮겨적는다
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	cout << solve(b) - solve(a - 1);
	
	return 0;
}
