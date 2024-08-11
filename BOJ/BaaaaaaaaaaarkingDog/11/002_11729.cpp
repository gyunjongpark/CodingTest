#include<iostream>
#include<cmath> //pow
using namespace std;
typedef unsigned long long ll;

int n;
ll ret;

void go(int a, int b, int n) { //a는 출발지, b는 목적지
	if (n == 1) { //원반이 한 개라면 direct로 옮길 수 있다
		cout << a << ' ' << b << '\n';
		return;
	}

	go(a, 6 - a - b, n - 1); //a 위치에 있는 1 ~ n-1번 원반을 c(6 - a - b)로 옮긴다
	cout << a << ' ' << b << '\n'; //a 위치에 있는 n번 원반을 목적지 b로 옮긴다
	go(6 - a - b, b, n - 1); //c 위치에 있는 n - 1개의 원반을 b로 옮긴다

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	ret = pow(2, n) - 1; //귀납적으로 도출한 이동 횟수

	cout << ret << '\n';
	go(1, 3, n);

	return 0;
}
